Pod::Spec.new do |s|
  s.name = "TGBaseIOT"
  s.version = "2.3.9.01"
  s.summary = "A short description of TGCommonBaseModule."
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"liubin"=>"liubin361163@163.com"}
  s.homepage = "https://gitee.com/tange-ai/tgopenbaseiot.git"
  s.description = "TODO: Add long description of the pod here."
  s.xcconfig = {"ENABLE_BITCODE"=>"NO"}
  s.source           = { :git => 'https://gitee.com/tange-ai/tgopenbaseiot2x.git', :tag => s.version.to_s }
#  s.compiler_flags ='-DLINUX','-D__MAC_OS__'
  s.ios.deployment_target    = '12.1'
#  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' ,'DEVELOPMENT_TEAM' => 'UAL776976T','OTHER_CFLAGS' => '-DLINUX -D__MAC_OS__'}
#  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64','DEVELOPMENT_TEAM' => 'UAL776976T','OTHER_CFLAGS' => '-DLINUX -D__MAC_OS__' }
  s.subspec 'BaseIOT' do |baseIOT|
    baseIOT.source_files = 'ios/Classes/BaseIOT/TGBaseIOT.framework/Headers/*.h'
    baseIOT.compiler_flags = '-DLINUX','-D__MAC_OS__'
    baseIOT.ios.vendored_frameworks   = 'ios/Classes/BaseIOT/**/*.framework'
    baseIOT.ios.vendored_libraries = 'ios/Classes/BaseIOT/**/*.a'
    baseIOT.frameworks = 'CoreGraphics', 'Security','UIKit','WebKit','CoreLocation','CoreMedia','CoreVideo','ImageIO','CoreText','AVFoundation'
    baseIOT.libraries = 'c++','sqlite3.0','z','iconv','xml2'
    baseIOT.dependency 'DAAudioVideo'
    baseIOT.dependency 'JSONKit','1.0.0'
    baseIOT.dependency 'ZXingObjC'
    baseIOT.dependency 'Masonry'
    baseIOT.dependency 'AFNetworking'
    baseIOT.dependency 'SVGKit','3.3.0'
    baseIOT.dependency 'CocoaLumberjack'
    baseIOT.dependency 'NTESVerifyCode'
    baseIOT.dependency 'MJExtension'
    baseIOT.dependency 'Socket.IO-Client-Swift','~> 15.2.0'
    baseIOT.dependency 'BabyBluetooth','~> 0.7.0'
  end
  s.subspec 'CloudService' do |cloudService|
    cloudService.requires_arc            = true
    cloudService.source_files = 'ios/Classes/CloudService/TGBaseIOTCloudService.framework/Headers/*.h'
    cloudService.ios.vendored_frameworks = 'ios/Classes/CloudService/OOS.framework','ios/Classes/CloudService/TGBaseIOTCloudService.framework'
    cloudService.dependency 'QCloudCOSXML'
    cloudService.dependency 'QCloudCore'
    cloudService.dependency 'AliyunOSSiOS'
    cloudService.dependency 'AliyunOSSiOS'
    cloudService.dependency 'TGBaseIOT/BaseIOT'
  end
end
