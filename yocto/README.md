README.md

$ yocto-layer create cwa-tools

layer structure:
(D) conf
  +- local.conf
COPYING.MIT
README
(D) recipes-cwa
  +- (D) xxx1
    +- xxx1.bb
  +- (D) xxx2
  	+- xxx2.bb
(D) recipes-cwa-bbappend

local.conf - Customizing Images
###
# We have a conf and classes directory, add to BBPATH
BBPATH .= ":${LAYERDIR}"

# We have a packages directory, add to BBFILES
BBFILES += "${LAYERDIR}/recipes-*/*/*.bb \
            ${LAYERDIR}/recipes-*/*/*.bbappend"

BBFILE_COLLECTIONS += "cwa-tools"
BBFILE_PATTERN_cwa-tools := "^${LAYERDIR}/"
BBFILE_PRIORITY_cwa-tools = "6"
###


*.bb files
###
DESCRIPTION = "..."
SUMMARY = "XXX - xxxxxx"
LICENSE = "MIT"
LICENSE_FLAGS = "commercial"
LIC_FILES_CHKSUM = "file://LICENSE;md5=39ec502560ab2755c4555ee8416dfe42"

DEPENDS = "..."
inherit xxx

SRC_URI = "file://..."

SRCBRANCH = "imx_4.1.15_1.0.0_ga"
SRCBRANCH ?= ""
SRC_URI = "git://github.com/xxx/xxx.git;branch=${SRCBRANCH}"

SRC_URI = "git://github.com/xxx/xxx.git;branch=${SRCBRANCH} \
	file://... \
"

# Add patches for gcc 6 compiler issue
SRC_URI += "file://gcc6_integrate_fix.patch \
            file://bcmhd_gcc6_indent_warning_error_fix.patch \
            file://gpu-viv_gcc6_indent_warning_error_fix.patch"
            

do_compile () {
}
do_install () {
}
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

Recipe [SYNTAX]:
* Variable Assignments and Manipulations & Using Variables
* Functions
* Keywords
* Comments, Line Continuation
* Assignment( Quote All Assignment, Conditional Assignment)
* Appending +=, Prepending =+, Appending _append, Prepending _prepend, Overrides

Recipe [COMMANDS]:
* Running a Build on the Recipe
* Fetching Code
