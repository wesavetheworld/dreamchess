/*  DreamChess
 *  Copyright (C) 2005  The DreamChess project
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

typedef struct vector3
{
    float e[3];
} vector3_t;

typedef struct matrix4x4
{
    float e[4][4];
} matrix4x4_t;

void mat_print(matrix4x4_t *mat);
matrix4x4_t mat_identity();
matrix4x4_t mat_multiply(matrix4x4_t *mat1, matrix4x4_t *mat2);