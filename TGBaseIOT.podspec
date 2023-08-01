Pod::Spec.new do |s|
  s.name = "TGBaseIOT"
  s.version = "1.3.5"
  s.summary = "A short description of TGCommonBaseModule."
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"liubin"=>"liubin361163@163.com"}
  s.homepage = "https://gitee.com/tange-ai/tgopenbaseiot2x.git"
  s.description = "TODO: Add long description of the pod here."
  s.xcconfig = {"ENABLE_BITCODE"=>"NO"}
  s.source           = { :git => 'https://gitee.com/tange-ai/tgopenbaseiot2x.git', :tag => s.version.to_s }
  s.compiler_flags ='-DLINUX','-D__MAC_OS__'
  s.ios.deployment_target    = '11.0'
#  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' ,'DEVELOPMENT_TEAM' => 'UAL776976T','OTHER_CFLAGS' => '-DLINUX -D__MAC_OS__'}
#  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64','DEVELOPMENT_TEAM' => 'UAL776976T','OTHER_CFLAGS' => '-DLINUX -D__MAC_OS__' }
  s.source_files = 'ios/TGBaseIOT.framework/Headers/*.h'
  s.ios.vendored_frameworks   = 'ios/**/*.framework'
  s.ios.vendored_libraries = 'ios/**/*.a'
  s.frameworks = 'CoreGraphics', 'Security','UIKit','WebKit','CoreLocation','CoreMedia','CoreVideo','ImageIO','CoreText','AVFoundation'
  s.libraries = 'c++','sqlite3.0','z','iconv','xml2'
  s.dependency 'JSONKit','1.0.0'
  s.dependency 'ZXingObjC'
  s.dependency 'Masonry'
  s.dependency 'AFNetworking'
  s.dependency 'SVGKit','3.3.0'
  s.dependency 'CocoaLumberjack'
  s.dependency 'QCloudCOSXML'
  s.dependency 'QCloudCore'
  s.dependency 'Socket.IO-Client-Swift','~> 15.2.0'
  s.dependency  'AliyunOSSiOS'
end
