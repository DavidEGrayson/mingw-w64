/*  Copyright (c) 2016 David Grayson

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <stdint.h>

/* Registry for long names, which get stored in a special archive
 * member named "//". */

/* Adds a name to the longnames string and returns offset of the first character. */
uint32_t longnames_add(const char * name);

/* Returns the length of the longnames string. */
uint32_t longnames_get_length();

/* Returns the null-terminated, newline-separated list of all the long names. */
const char * longnames_get_string();
