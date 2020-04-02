function Start()
    SetOrigin(Graphics, "MiddleCenter")

    SetLocation(Transform, 100.0, 100.0)
    --Move(Transform, 0.0, 5.0)

    --SetRotation(Transform, 90.0)
    --Rotate(Transform, 5.0)

    --SetScale(Transform, 2.0, 2.0)
    --Scale(Transform, 0.9999, 0.9999)
end

function Update()
    SetLocation(Transform, 0.0, -0.25)
end