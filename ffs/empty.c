/*
 * There is probably a better solution than this, but I'm not going to
 * go looking for it right now.  There are three sublibraries built in
 * this project.  I want them all to appear in the top-level directory
 * at the end so that macros like CERCS_REQUIRE_PACKAGE can find
 * them.  I can't use symlinks because that confuses libtool.  So I
 * was using libtool to relink these libraries as a mechanism for
 * moving them into the top directory.  But on Darwin, libtool dies
 * when there are no objects that we're linking at the top level.  So,
 * this file is introduced simply to avoid that error.  Sigh.
 */
static void
evpath_not_used()
{}
