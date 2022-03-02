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
#include "../../../inc/MarlinConfigPre.h"

#if ENABLED(DWIN_LCD_PROUI)

#include "dwin.h"
<<<<<<< HEAD
#include "dwin_popup.h"

void Draw_Select_Highlight(const bool sel) {
  HMI_flag.select_flag = sel;
  const uint16_t c1 = sel ? HMI_data.Highlight_Color : HMI_data.PopupBg_color,
                 c2 = sel ? HMI_data.PopupBg_color : HMI_data.Highlight_Color;
  DWIN_Draw_Rectangle(0, c1, 25, 279, 126, 318);
  DWIN_Draw_Rectangle(0, c1, 24, 278, 127, 319);
  DWIN_Draw_Rectangle(0, c2, 145, 279, 246, 318);
  DWIN_Draw_Rectangle(0, c2, 144, 278, 247, 319);
=======
#include "dwinui.h"
#include "dwin_popup.h"

void (*ClickPopup)()=nullptr;
void (*PopupChange)(bool state)=nullptr;
void (*Draw_Popup)()=nullptr;
uint16_t HighlightYPos = 280;

void Draw_Select_Highlight(const bool sel, const uint16_t ypos) {
  HighlightYPos = ypos;
  HMI_flag.select_flag = sel;
  const uint16_t c1 = sel ? HMI_data.Highlight_Color : HMI_data.PopupBg_color,
                 c2 = sel ? HMI_data.PopupBg_color : HMI_data.Highlight_Color;
  DWIN_Draw_Rectangle(0, c1, 25, ypos - 1, 126, ypos + 38);
  DWIN_Draw_Rectangle(0, c1, 24, ypos - 2, 127, ypos + 39);
  DWIN_Draw_Rectangle(0, c2, 145, ypos - 1, 246, ypos + 38);
  DWIN_Draw_Rectangle(0, c2, 144, ypos - 2, 247, ypos + 39);
>>>>>>> upstream
}

void DWIN_Popup_Continue(const uint8_t icon, FSTR_P const fmsg1, FSTR_P const fmsg2) {
  HMI_SaveProcessID(WaitResponse);
<<<<<<< HEAD
  DWIN_Draw_Popup(icon, fmsg1, fmsg2, ICON_Continue_E);  // Button Continue
=======
  DWIN_Draw_Popup(icon, fmsg1, fmsg2, BTN_Continue);  // Button Continue
>>>>>>> upstream
  DWIN_UpdateLCD();
}

void DWIN_Popup_ConfirmCancel(const uint8_t icon, FSTR_P const fmsg2) {
  DWIN_Draw_Popup(ICON_BLTouch, F("Please confirm"), fmsg2);
<<<<<<< HEAD
  DWINUI::Draw_IconWB(ICON_Confirm_E, 26, 280);
  DWINUI::Draw_IconWB(ICON_Cancel_E, 146, 280);
  Draw_Select_Highlight(true);
  DWIN_UpdateLCD();
}

=======
  DWINUI::Draw_Button(BTN_Confirm, 26, 280);
  DWINUI::Draw_Button(BTN_Cancel, 146, 280);
  Draw_Select_Highlight(HMI_flag.select_flag);
  DWIN_UpdateLCD();
}

void Goto_Popup(void (*onPopupDraw)(), void (*onClickPopup)() /*= nullptr*/, void (*onPopupChange)(bool state) /*= nullptr*/) {
  Draw_Popup = onPopupDraw;
  ClickPopup = onClickPopup;
  PopupChange = onPopupChange;
  HMI_SaveProcessID(Popup);
  HMI_flag.select_flag = false;
  Draw_Popup();
}

void HMI_Popup() {
  if (!wait_for_user) {
    if (ClickPopup) ClickPopup();
    return;
  }
  else {
    EncoderState encoder_diffState = get_encoder_state();
    if (encoder_diffState == ENCODER_DIFF_CW || encoder_diffState == ENCODER_DIFF_CCW) {
      const bool change = encoder_diffState != ENCODER_DIFF_CW;
      if (PopupChange) PopupChange(change); else Draw_Select_Highlight(change, HighlightYPos);
      DWIN_UpdateLCD();
    }
  }
}

>>>>>>> upstream
#endif // DWIN_LCD_PROUI
