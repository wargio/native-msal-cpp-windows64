project('native-msal-cpp', 'cpp',
  version: '0.1.0',
  license: ['MIT'],
  default_options : [
    'buildtype=debugoptimized',
    'b_vscrt=from_buildtype',
    'cpp_std=c++14'
  ],
  meson_version: '>=0.60.0')

# Do some sanity checking so that meson can fail early instead of at final link time
expected_host = host_machine.system() == 'windows' or host_machine.system() == 'darwin'
expected_cpus = host_machine.cpu_family() == 'x86_64' or host_machine.cpu_family() == 'x86' or host_machine.cpu_family() == 'aarch64'

if not expected_host or not expected_cpus
  error('msalruntime is a binary wrap for windows and darwin x64/x86/arm64 only. you should not compile this outside of windows or macos.')
endif

msalruntime_proj = subproject('msalruntime-' + target_machine.system() + '-' + target_machine.cpu_family())
msalruntime_dep = msalruntime_proj.get_variable('msalruntime_dep')

app_client_id = get_option('appid')
app_authority = get_option('tenant')

if app_client_id == ''
  # On Azure AD/Entra ID is called "Application (client) ID"
  error('Please set -Dappid=xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx (your Microsoft Azure AD/Entra ID application uuid)')
elif app_authority == ''
  # On Azure AD/Entra ID is called "Directory (tenant) ID"
  error('Please set -Dtenant=yyyyyyyy-yyyy-yyyy-yyyy-yyyyyyyyyyyy (your Microsoft Azure AD/Entra ID directory/tenant uuid)')
endif

msal_examples_cpp_args = [
  '-DAPP_ID="@0@"'.format(app_client_id),
  '-DAUTH_ID="@0@"'.format(app_authority),
]

msal_examples_deps = [
  msalruntime_dep,
]

msal_examples = [
  'msal_acquire_token_interactively',
  'msal_acquire_token_silently',
  'msal_signin',
  'msal_signin_interactive',
  'msal_signin_silently',
  'msal_signout_silently'
]

foreach file : msal_examples
  executable(file, ['sources' / '@0@.cpp'.format(file)],
    cpp_args: msal_examples_cpp_args,
    include_directories: include_directories('sources'),
    dependencies: msal_examples_deps,
    install: true,
    implicit_include_directories: false
  )
endforeach
