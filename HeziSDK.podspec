Pod::Spec.new do |s|
s.name = 'HeziSDK'
s.version = '1.2.1'
s.license = 'MIT'
s.summary = '活动盒子SDK'
s.homepage = 'https://github.com/mcmore/hezi-demo-for-ios'
s.authors = { 'mcmore' => 'ljcoder@163.com' }
s.source = { :git => "https://github.com/mcmore/hezi-demo-for-ios.git", :tag => "1.2.1"}
s.requires_arc = true
s.ios.deployment_target = '7.0'
s.source_files = "HeziSDK", "*.{h,m,a}"
end