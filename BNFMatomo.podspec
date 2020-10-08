require "json"
package = JSON.parse(File.read('package.json'))

Pod::Spec.new do |s|
  s.name          = "BNFMatomo"
  s.version       = package['version']
  s.summary       = package['description']
  s.author        = package['author']
  s.license       = package['license']
  s.requires_arc  = true
  s.homepage      = package['homepage']
  s.source        = { :git => 'https://github.com/BonifyByForteil/react-native-matomo.git' }
  s.platform      = :ios, '9.0'
  s.source_files  = "ios/{BNFMatomo,MatomoTracker}/**/*.{m,h,swift}"
  s.static_framework = true
  s.swift_version = '4.2'
  
  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES' }
  s.dependency "React-Core"
end
