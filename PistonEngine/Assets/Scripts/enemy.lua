movingDown = false
movingLeft = false
movingRight = false
alive = true
gameTimer = 125
timeUntilAttack = 0

function Start(args)
    SetOrigin(Graphics, "MiddleCenter")

    --timeUntilAttack = args[1]

    animIdle = {name = "Idle"}
    CreateAnim(Graphics, animIdle)

    animDead = {name = "Dead", texture="../../Assets/Textures/enemy.png", animated = true, textureX = 0, textureY = 128, textureWidth = 32, textureHeight = 32, frameTime = 0.1, looping = false}
    CreateAnim(Graphics, animDead)

    animWalk = {name = "Walk", texture="../../Assets/Textures/enemy.png", animated = true, textureX = 0, textureY = 64, textureWidth = 32, textureHeight = 32, frameTime = 0.1, looping = true}
    CreateAnim(Graphics, animWalk)

    animAttack = {name = "Attack", texture="../../Assets/Textures/enemy.png", animated = true, textureX = 0, textureY = 96, textureWidth = 32, textureHeight = 32, frameTime = 0.1, looping = false}
    CreateAnim(Graphics, animAttack)

    PlayAnim(Graphics, animWalk)

end

function Update(dt)
    gameTimer = gameTimer - (dt/1)

    if (125 - gameTimer > timeUntilAttack) then
	SetLocation(Transform, 1000, 1000)
    end

    if (alive) then
        moveAI()

        if (movingDown) then
            SetLocation(Transform, 0.0, 0.01)
        end

        if (movingLeft) then
            SetLocation(Transform, -0.10, 0.0)
        end

        if (movingRight) then
            SetLocation(Transform, 0.10, 0.0)
        end
    end
end

function moveAI()

    if (GetLocationX(Transform) < 1) then
        movingRight = true
        movingLeft = false
        movingDown = false

    elseif (GetLocationX(Transform) > (512 - GetWidth(Graphics))) then
        movingRight = false
        movingLeft = true
        movingDown = false
    end

    if (GetLocationX(Transform) < 1) then
        movingDown = true
    end
end


function Collision(obj1Name, obj2Name)
    obj2Name = obj2Name:sub(1, -2)
    if (obj2Name == "arrow") then
        alive = false
        SetLocation(Transform, 1000, 1000)
    end
end