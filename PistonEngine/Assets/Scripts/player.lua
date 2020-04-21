movingUp = false
movingDown = false
movingLeft = false
movingRight = false

rotateLeft = false
rotateRight = false
myName = ""
paused = false
alive = true
function Start(args)
    myName = GetName(GameObject)

    SetOrigin(Graphics, "MiddleCenter")

    animIdle = {name = "Idle"}
    CreateAnim(Graphics, animIdle)

    animDead = {name = "Dead", texture="../../Assets/Textures/player.png", animated = true, textureX = 0, textureY = 128, textureWidth = 32, textureHeight = 32, frameTime = 0.1, looping = false}
    CreateAnim(Graphics, animDead)

    animAttack = {name = "Attack", texture="../../Assets/Textures/player.png", animated = true, textureX = 0, textureY = 96, textureWidth = 32, textureHeight = 32, frameTime = 0.1, looping = false}
    CreateAnim(Graphics, animAttack)

    PlayAnim(Graphics, animIdle)

end

function Update(dt)
    if (alive) then
        if (movingUp) then
            SetLocation(Transform, 0.0, -0.10)
        end

        if (movingDown) then
            SetLocation(Transform, 0.0, 0.10)
        end

        if (movingLeft) then
            SetLocation(Transform, -0.10, 0.0)
        end

        if (movingRight) then
            SetLocation(Transform, 0.10, 0.0)
        end

        if (rotateLeft) then
            SetRotation(Transform, -0.10, 0.0, 0.0)
        end

        if (rotateRight) then
            SetRotation(Transform, 0.10, 0.0, 0.0)
        end
    end
end

function KeyInput(state, keyCode, mousePosX, mousePosY)

    if (state == true) then
        if (keyCode == 73 or keyCode == 22) then
            movingUp = true
        elseif (keyCode == 74 or keyCode == 18) then
            movingDown = true
        elseif (keyCode == 71 or keyCode == 0) then
            movingLeft = true
        elseif (keyCode == 72 or keyCode == 3) then
            movingRight = true  

        elseif (keyCode == 16) then
            Pause()
        end     

    elseif (state == false) then
        if (keyCode == 73 or keyCode == 22) then
            movingUp = false
        elseif (keyCode == 74 or keyCode == 18) then
            movingDown = false
        elseif (keyCode == 71 or keyCode == 0) then
            movingLeft = false
        elseif (keyCode == 72 or keyCode == 3) then
            movingRight = false  

        end 
    end
end

function MouseInput(state, keyCode, mousePosX, mousePosY)
    if (state == true) then
        if (keyCode == 0) then
            tempX = GetLocationX(Transform)
            tempY = GetLocationY(Transform)

            arrow = {
                name = "arrow", 
                position = {x = tempX, y = tempY}, 
                rotation = {angle = 0.0, x = 0.0, y = 0.0}, 
                scale = {x = 1.0, y = 1.0}, 
                graphics = {name = "arrow", texture="../../Assets/Textures/arrow.png", animated = true, textureX = 0, textureY = 0, textureWidth = 16, textureHeight = 64, frameTime = 0.1, looping = true}, 
                script = {location = "../../Assets/Scripts/arrow.lua", args = {arg1 = mousePosX, arg2 = mousePosY}},
                rigidBody = {mass = 1.0, restitution = 1.0, obeysGravity = false}
                }

            PlayAnim(Graphics, animAttack)
            Create(GameObject, arrow)
	    return

        elseif (keyCode == 1) then
            --Doesn't Work
            --LoadScene(GameObject, "../../Assets/Scenes/scene2.json")
            temp = {
                name = "root",
                var1 = 0
            }
            SendData(GameObject, temp)
        elseif (keyCode == 2) then
        end     

    elseif (state == false) then
        if (keyCode == 0) then
	    return
        elseif (keyCode == 1) then
        elseif (keyCode == 2) then
        end    
    end
end

function Pause()
    if (not paused) then
        PauseGame(GameObject)
    else
        ResumeGame(GameObject)
    end
    paused = not paused
end

function Collision(obj1Name, obj2Name)
    if (obj2Name == "enemy") then
        PlayAnim(Graphics, animDead)
        alive = false
    end
end


function ReceiveData(args)
    print("Received " .. args[0])
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

