/*  member_names.c - Manages a string that holds the filenames of most of
    the members of the archive.  This string is put in the special member
    named "//".

    Copyright (c) 2016 David Grayson

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

#include "member_names.h"
#include <string.h>
#include <stdlib.h>

static uint32_t member_names_length = 0;
static uint32_t member_names_capacity = 0;
static char * member_names_str = NULL;

uint32_t member_names_add(const char * name)
{
    const uint32_t len = strlen(name);
    const uint32_t offset = member_names_length;
    const uint32_t new_length = member_names_length + len + 1;
    if (new_length + 1 > member_names_capacity)
    {
        const uint32_t new_capacity = (new_length + 1) * 2;
        char * new_str = realloc(member_names_str, new_capacity);
        // assume realloc was successful
        member_names_str = new_str;
        member_names_capacity = new_capacity;
    }
    strcpy(member_names_str + member_names_length, name);
    member_names_length = new_length;
    member_names_str[member_names_length - 1] = '\n';
    member_names_str[member_names_length] = '\0';
    return offset;
}

uint32_t member_names_get_length()
{
    return member_names_length;
}

const char * member_names_get_string()
{
    return member_names_str;
}

void  __attribute__((destructor)) member_names_reset()
{
    if (member_names_str)
    {
        free(member_names_str);
        member_names_str = NULL;
        member_names_length = 0;
        member_names_capacity = 0;
    }
}
