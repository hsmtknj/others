; =====================
; Delete
; =====================

; 無変換+h→backspace
sc07B & h:: Send, {Blind}{BS}
; 無変換+d→delete
sc07B & d:: Send, {Blind}{Del}


; =====================
; Move cursor
; =====================

; FBNP
sc07B & b:: Send, {Blind}{Left}
sc07B & n:: Send, {Blind}{Down}
sc07B & f:: Send, {Blind}{Right}
sc07B & p:: Send, {Blind}{Up}

; Apply this setting to use OneNote
; Cannot move cursor with above settings in OneNote for some reaseon
#IfWinActive, ahk_class Framework::CFrame
    sc07B & p::dllcall("keybd_event", int, 0x26, int, 0, int, 1, int, 0)  ; Up
    sc07B & n::dllcall("keybd_event", int, 0x28, int, 0, int, 1, int, 0)  ; Down
#IfWinActive

; Home and End
sc07B & a::Send,{Blind}{Home}   ; Muhenkan + a = Home 
sc07B & e::Send,{Blind}{End}    ; Muhenkan + e = End 


; =====================
; 無変換、変換キーの単独機能保持
; =====================

; 無変換キー単独は無変換キーとして機能させる
sc07B:: Send {Blind}{sc07B}
; 変換キー単独は変換キーとして機能させる
sc079:: Send {Blind}{sc079}


; =====================
; Others
; =====================

; sc07B & m::Send, {Blind}{Return}  ; 無変換 + m = Return
; !k::Send,{F7}                     ; Alt + k = F7 (カナ変換用)
sc07B & k:: Send, {F7}              ; 無変換 + k = F7 (カナ変換用)
sc07B & i:: Send, {F2}              ; 無変換 + i = F2 (rename, エクセルのセル編集, ...)
sc07B & j:: Send, {F7}              ; 無変換 + j = ESC

;End of file