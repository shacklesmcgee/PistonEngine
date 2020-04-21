movingDown = false
movingLeft = false
movingRight = false
alive = true

function Start(args)
    SetOrigin(Graphics, "MiddleCenter")

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
    if (obj2Name ~= "player") then
        --Destroy(GameObject, obj2Name)
        alive = false
        SetLocation(Transform, 1000, 1000)
    end
end