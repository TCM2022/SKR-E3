/**
 * DWIN End Stops diagnostic page
 * Author: Miguel A. Risco-Castillo
<<<<<<< HEAD
 * Version: 1.0
 * Date: 2021/11/06
=======
 * Version: 1.2.3
 * Date: 2022/02/24
>>>>>>> upstream
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

class ESDiagClass {
public:
  void Draw();
  void Update();
};

extern ESDiagClass ESDiag;
