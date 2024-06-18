/** \file tgutil.h
 * \brief 辅助工具api
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ZT_OPTICAL,
    ZT_DIGITAL,
    ZT_SIMULATE
} ZOOMTYPE;

//如果没有指定各ZOOMDESC的nSteps, 全部步数(ZOOMCAP::nSteps)在各ZOOMDESC间分配策略
typedef enum {
    DISTRIB_ASIS,   //as described in feature string
    DISTRIB_EVENLY, //全局平均: step位置的间隔为 1/(nSteps-1)
    DISTRIB_BY_ZOOM, //放大倍数大的ZOOMDESC，分配的点位越多
    DISTRIB_MANUALLY, //在配置里指定（通过 '/n'.例如: S3/4）
} DISTRIBSTRATEGY;

typedef struct {
    ZOOMTYPE zt;
    float fZoom;   //放大倍数 
    float fRepresent; //表征放大倍数
    int nSteps; //步数. 如果没有设置则为0
} ZOOMDESC;

#define MAX_LENSES 4
typedef struct ZOOMCAP {
    int nLenses;  //镜头数(N-目)
    int nSteps;  //总步数
    float fZoomTotal;  //总放大倍数
    float fTotalRepresent; //总表征放大倍数
    DISTRIBSTRATEGY distrib;
    int nDescs; 
    ZOOMDESC zdesc[MAX_LENSES];
} ZOOMCAP;

/** 解析 Cap-Zoom 能力
 * \param s
 * \param zcap
 * \param strategy
 * \param defSteps steps if not specific in s
 * \return 1:ok; 0:failed
 */
int ParseZoomFeature(const char *s, ZOOMCAP *zcap, DISTRIBSTRATEGY strategy, int defSteps);

/** 能力是否会每一段指定了步数.
 *
 * \retval 1 在每个ZOOMDESC里指定步数(描述里通过 "/N")
 *  \retval 0 有只总步数
 */
int Zoomcap_has_individual_steps(const ZOOMCAP *zcap);

/** ZOOM位置的各种表示.这些值是相互匹配的 */
typedef struct {
    int idx_zd; ///< index of ZOOMDESC, 在 ZOOMCAP::zdesc
    int idx_step; ///< n-th step in ZOOMDESC(如果ZOOMDESC设置了nSteps), 或 -1
    float zoom_local; ///< 对应idx_zd要执行的放大倍数.
    float zoom; ///< 放大倍数
    float z;   ///< 0.0~1.0
    //for APP
    int pos; ///< 对应app滑动轴上的位置
    float vZoom; ///< 使用表征值计算出来的zoom值
} ZOOMPOS;

/**
 * @brief 由z计算ZOOMPOS.
 *
 * @param zcap
 * @param z
 * @param t 保存计算结果
 * @param no_magnetic 为0时会校正到最近的 step 对应的位置. 应用中应该始终传0
 */
void Zoompos_from_z(const ZOOMCAP *zcap, float z, ZOOMPOS *t, int no_magnetic);

/**
 * @brief 由zoom计算 ZOOMPOS.
 *
 * @param zcap
 * @param zoom 为真实放大倍数
 * @param t 保存计算结果
 * @param no_magnetic 为0时会校正到最近的 step 对应的位置. 应用中应该始终传0
 */
void Zoompos_from_zoom(const ZOOMCAP *zcap, float zoom, ZOOMPOS *t, int no_magnetic);

/**
 * @brief 由局步步数计算ZOOMPOS
 *
 * @param zcap
 * @param idx_zd
 * @param idx_step  为 ZOOMCAP::zdesc 中第 idx_zd 个 ZOOMDESC 内steps的索引
 * @param zp 输出
 */
void Zoompos_from_local_step(const ZOOMCAP *zcap, int idx_zd, int idx_step, ZOOMPOS *zp);

/**
 * @brief 由全局步数计算ZOOMPOS
 *
 * @param zcap
 * @param step 全部步数的索引
 * @param zp 结果
 */
void Zoompos_from_step(const ZOOMCAP *zcap, int step, ZOOMPOS *zp);

// z ==> pos, for even step stride(non-individual steps)
int z2pos_even(const ZOOMCAP *zcap, float z);

/** 获取某个ZOOMDESC最小步数对应的位置值
 * \param idx_zd ZOOMDESC的索引
 */
void Zoompos_of_min(const ZOOMCAP *zcap, int idx_zd, ZOOMPOS *zp);

/** 获取某个ZOOMDESC最大步数对应的位置值
 * \param idx_zd ZOOMDESC的索引
 */
void Zoompos_of_max(const ZOOMCAP *zcap, int idx_zd, ZOOMPOS *zp);

#ifdef __cplusplus
} /* extern "C" */
#endif
