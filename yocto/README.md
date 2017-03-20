README.md

$ yocto-layer create cwa-tools

layer structure:
(D) conf
COPYING.MIT
README
(D) recipes-example
(D) recipes-example-bbappend

local.conf - Customizing Images
###

*.bb files
###
IMAGE_INSTALL = ""
###

*.bb files - Custom Package Groups

basic process for creating a new recipe.
Establish the Recipe
Fetch Source Files
Unpack Source Files
Patching Source Files
Add Licensing Information
Add Configurations
Compilation
Autotools or CMake( NO - Create Your Own do_install )
Need Supporting Service?
Packaging
Provide Post-Installation Scripts
Perform Runtime Testing