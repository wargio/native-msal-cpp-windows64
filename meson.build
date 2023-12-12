project('native-msal-cpp-windows', 'cpp',
  version: '0.1.0',
  license: ['MIT'],
  default_options : [
    'buildtype=debugoptimized',
    'b_vscrt=from_buildtype',
    'cpp_std=c++14'
  ],
  meson_version: '>=0.60.0')

# Do some sanity checking so that meson can fail early instead of at final link time
if not (host_machine.system() == 'windows' and host_machine.cpu_family() == 'x86_64')
  error('msalruntime is a binary wrap for x64_64 Windows only. you should not compile this outside of windows.')
endif

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
  dependency('msalruntime'),
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
