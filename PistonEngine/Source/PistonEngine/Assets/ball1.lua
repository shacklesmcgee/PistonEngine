movingUp = false
movingDown = false;
movingLeft = false;
movingRight = false;

function Start()
    --SetOrigin(Graphics, "TopLeft")
    --SetOrigin(Graphics, "TopCenter")
    --SetOrigin(Graphics, "TopRight")
    --SetOrigin(Graphics, "MiddleLeft")
    SetOrigin(Graphics, "MiddleCenter")
    --SetOrigin(Graphics, "MiddleRight")
    --SetOrigin(Graphics, "BottomLeft")
    --SetOrigin(Graphics, "BottomCenter")
    --SetOrigin(Graphics, "BottomRight")

    --Rotate(Transform, 25.0)
end

function Update()
    if (movingUp) then
        SetLocation(Transform, 0.0, -0.25)
    end

    if (movingDown) then
        SetLocation(Transform, 0.0, 0.25)
    end

    if (movingLeft) then
        SetLocation(Transform, -0.25, 0.0)
    end

    if (movingRight) then
        SetLocation(Transform, 0.25, 0.0)
    end
end

function Input(state, keyCode)
    if (state == true) then
        if (keyCode == 73) then
            movingUp = true
        elseif (keyCode == 74) then
            movingDown = true
        elseif (keyCode == 71) then
            movingLeft = true
        elseif (keyCode == 72) then
            movingRight = true   
        end     
    elseif (state == false) then
        if (keyCode == 73) then
            movingUp = false
        elseif (keyCode == 74) then
            movingDown = false
        elseif (keyCode == 71) then
            movingLeft = false
        elseif (keyCode == 72) then
            movingRight = false   
        end 
    end
end

function MoveUp()
    SetLocation(Transform, 0.0, -2.5)
end

keyCodes = {
    "A", --0
    "B", --1
    "C", --2
    "D", --3
    "E", --4
    "F", --5
    "G", --6
    "H", --7
    "I", --8
    "J", --9
    "K", --10
    "L", --11
    "M", --12
    "N", --13
    "O", --14
    "P", --15
    "Q", --16
    "R", --17
    "S", --18
    "T", --19
    "U", --20
    "V", --21
    "W", --22
    "X", --23
    "Y", --24
    "Z", --25
    "Num0", --26
    "Num1", --27
    "Num2", --28
    "Num3", --29
    "Num4", --30
    "Num5", --31
    "Num6", --32
    "Num7", --33
    "Num8", --34
    "Num9", --35
    "Escape", --36
    "LControl", --37
    "LShift", --38
    "LAlt", --39
    "LSystem", --40
    "RControl", --41
    "RShift", --42
    "RAlt", --43
    "RSystem", --44
    "Menu", --45
    "LBracket", --46
    "RBracket", --47
    "SemiColon", --48
    "Comma", --49
    "Period", --50
    "Quote", --51
    "Slash", --52
    "BackSlash", --53
    "Tilde", --54
    "Equal", --55
    "Dash", --56
    "Space", --57
    "Return", --58
    "Back", --59
    "Tab", --60
    "PageUp", --61
    "PageDown", --62
    "End", --63
    "Home", --64
    "Insert", --65
    "Delete", --66
    "Add", --67
    "Subtract", --68
    "Multiply", --69
    "Divide", --70
    "Left", --71
    "Right", --72
    "Up", --73
    "Down", --74
    "Numpad0", --75
    "Numpad1", --76
    "Numpad2", --77
    "Numpad3", --78
    "Numpad4", --79
    "Numpad5", --80
    "Numpad6", --81
    "Numpad7", --82
    "Numpad8", --83
    "Numpad9", --84
    "F1", --85
    "F2", --86
    "F3", --87
    "F4", --88
    "F5", --89
    "F6", --90
    "F7", --91
    "F8", --92
    "F9", --93
    "F10", --94
    "F11", --95
    "F12", --96
    "F13", --97
    "F14", --98
    "F15", --99
    "Pause", --101
    "Count" --101
}

