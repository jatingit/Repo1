/* Pango
 * pango-utils.c: Utilities for internal functions and modules
 *
 * Copyright (C) 2000 Red Hat Software
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <stdio.h>
#include <glib.h>

char    *pango_trim_string     (const char *str);
char **  pango_split_file_list (const char *str);

gboolean pango_read_line      (FILE        *stream,
			       GString     *str);

gboolean pango_skip_space     (const char **pos);
gboolean pango_scan_word      (const char **pos,
			       GString     *out);
gboolean pango_scan_string    (const char **pos,
			       GString     *out);
gboolean pango_scan_int       (const char **pos,
			       int         *out);

char *   pango_config_key_get (const char  *key);

/* Functions for parsing textual representations
 * of PangoFontDescription fields. They return TRUE if the input string
 * contains a valid value, which then has been assigned to the corresponding
 * field in the PangoFontDescription.
 */
gboolean pango_parse_style   (GString              *str,
			      PangoFontDescription *desc);
gboolean pango_parse_variant (GString               *str,
			      PangoFontDescription *desc);
gboolean pango_parse_weight  (GString               *str,
			      PangoFontDescription *desc);
gboolean pango_parse_stretch (GString               *str,
			      PangoFontDescription *desc);

/* On Unix, return the name of the "pango" subdirectory of SYSCONFDIR
 * (which is set at compile time). On Win32, return the Pango
 * installation directory (which is set at installation time, and
 * stored in the registry). The returned string should not be
 * g_free'd.
 */
char *   pango_get_sysconf_subdirectory (void);

/* Ditto for LIBDIR/pango. On Win32, use the same Pango
 * installation directory. This returned string should not be
 * g_free'd either.
 */
char *   pango_get_lib_subdirectory (void);
