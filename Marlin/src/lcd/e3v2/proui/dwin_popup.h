/**
 * DWIN UI Enhanced implementation
 * Author: Miguel A. Risco-Castillo
<<<<<<< HEAD
 * Version: 3.10.1
 * Date: 2022/01/21
=======
 * Version: 3.11.1
 * Date: 2022/02/28
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

#include "dwinui.h"
#include "dwin.h"

<<<<<<< HEAD
// Popup windows

void Draw_Select_Highlight(const bool sel);
=======
extern void (*Draw_Popup)();

void Draw_Select_Highlight(const bool sel, const uint16_t ypos);
inline void Draw_Select_Highlight(const bool sel) { Draw_Select_Highlight(sel, 280); };
void DWIN_Popup_Continue(const uint8_t icon, FSTR_P const fmsg1, FSTR_P const fmsg2);
void DWIN_Popup_ConfirmCancel(const uint8_t icon, FSTR_P const fmsg2);
void Goto_Popup(void (*onPopupDraw)(), void (*onClickPopup)() = nullptr, void (*onPopupChange)(bool state) = nullptr);
void HMI_Popup();
>>>>>>> upstream

inline void Draw_Popup_Bkgd() {
  DWIN_Draw_Rectangle(1, HMI_data.PopupBg_color, 14, 60, 258, 330);
  DWIN_Draw_Rectangle(0, HMI_data.Highlight_Color, 14, 60, 258, 330);
}

template<typename T, typename U>
void DWIN_Draw_Popup(const uint8_t icon, T amsg1=nullptr, U amsg2=nullptr, uint8_t button=0) {
  DWINUI::ClearMenuArea();
  Draw_Popup_Bkgd();
  if (icon) DWINUI::Draw_Icon(icon, 101, 105);
  if (amsg1) DWINUI::Draw_CenteredString(HMI_data.PopupTxt_Color, 210, amsg1);
  if (amsg2) DWINUI::Draw_CenteredString(HMI_data.PopupTxt_Color, 240, amsg2);
<<<<<<< HEAD
  if (button) DWINUI::Draw_IconWB(button, 86, 280);
=======
  if (button) DWINUI::Draw_Button(button, 86, 280);
>>>>>>> upstream
}

template<typename T, typename U>
void DWIN_Show_Popup(const uint8_t icon, T amsg1=nullptr, U amsg2=nullptr, uint8_t button=0) {
  DWIN_Draw_Popup(icon, amsg1, amsg2, button);
  DWIN_UpdateLCD();
}

template<typename T, typename U>
void DWIN_Popup_Confirm(const uint8_t icon, T amsg1, U amsg2) {
  HMI_SaveProcessID(WaitResponse);
<<<<<<< HEAD
  DWIN_Draw_Popup(icon, amsg1, amsg2, ICON_Confirm_E);  // Button Confirm
  DWIN_UpdateLCD();
}

void DWIN_Popup_Continue(const uint8_t icon, FSTR_P const fmsg1, FSTR_P const fmsg2);

void DWIN_Popup_ConfirmCancel(const uint8_t icon, FSTR_P const fmsg2);
=======
  DWIN_Draw_Popup(icon, amsg1, amsg2, BTN_Confirm);  // Button Confirm
  DWIN_UpdateLCD();
}

>>>>>>> upstream
