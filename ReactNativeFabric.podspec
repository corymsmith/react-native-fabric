require 'json'

package = JSON.parse(File.read(File.join(__dir__, 'package.json')))

Pod::Spec.new do |s|
  s.name                = 'ReactNativeFabric'
  s.version             = package['version']
  s.summary             = package['description']
  s.description         = package['description']
  s.homepage            = package['homepage']
  s.license             = package['license']
  s.author              = package['author']
  s.source              = { :git => 'https://github.com/corymsmith/react-native-fabric.git', :tag => 'v'+s.version.to_s }

  s.ios.deployment_target = '9.0'
  s.tvos.deployment_target = '9.0'

  s.dependency 'React'
  s.dependency 'Fabric'
  s.dependency 'Crashlytics'
  s.ios.xcconfig = {
    'FRAMEWORK_SEARCH_PATHS' => '"${PODS_ROOT}/Crashlytics/iOS" "${PODS_ROOT}/Fabric/iOS"',
    'OTHER_LDFLAGS' => '-framework Crashlytics -framework Fabric'
  }

  s.preserve_paths      = 'README.md', 'LICENSE', 'package.json'
  s.source_files        = 'ios/**/*.{h,m}'
  s.exclude_files       = 'android/**/*'
end
