Pod::Spec.new do |s|
  s.name = 'm2b-ios-sdk-compiled'
  s.version = '2.0.33'
  s.summary = 'Provides lots of useful classes used by Mobile2b internally and several adapter classes to be used with the Mobile2b Cloud.'
  s.license = 'Unspecified'
  s.authors = [{"Robert Vennemann"=>"vennemann@mobile2b.de"}, {"Joachim Kurz"=>"kurz@mobile2b.de"}]
  s.homepage = 'http://www.mobile2b.de'
  s.frameworks = 'Foundation'
  s.requires_arc = true
  s.source = { :git => "git@github.com:Mobile2b/m2b-ios-sdk-compiled.git", :tag => s.version.to_s }

  s.platform = :ios, '6.0'
  s.ios.platform             = :ios, '6.0'
  s.ios.preserve_paths       = 'ios/m2b-ios-sdk.framework'
  s.ios.public_header_files  = 'ios/m2b-ios-sdk.framework/Versions/A/Headers/*.h'
  s.ios.resource             = 'ios/m2b-ios-sdk.framework/Versions/A/Resources/**/*'
  s.ios.vendored_frameworks  = 'ios/m2b-ios-sdk.framework'
end
