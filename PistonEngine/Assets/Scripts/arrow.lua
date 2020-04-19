targetX = 0
targetY = 0
speed = 0.25

function Start(args)
    SetOrigin(Graphics, "MiddleCenter")
    
    arrowAnim = {name = "arrow"}
    PlayAnim(Graphics, arrowAnim);
    print(GetLocationX(Transform))
    print(GetLocationY(Transform))
    
    targetX = args[1] - (GetLocationX(Transform) + GetWidth(Graphics)/2)
    targetY = args[2] - (GetLocationY(Transform) + GetHeight(Graphics)/2)

    norm = math.sqrt((targetX ^ 2) + (targetY ^ 2))
    targetX = targetX / norm
    targetY = targetY / norm

    degrees = math.deg(math.atan(targetX, targetY))
    SetRotation(Transform, degrees, 0.0, 0.0)
end

function Update()
    SetLocation(Transform, targetX * speed, targetY * speed)
end