gameTimer = -1

function Start(args)
    SetLocation(Transform, 0, -225)
    SetTextOrigin(Text, "MiddleCenter")
end

function Update(dt)

    gameTimer = gameTimer - (dt/1)
    
    seconds = gameTimer % 60
    minutes = (gameTimer / 60) % 60

    minutes = minutes - 0.5 - (minutes + 0.5) % 1
    seconds = seconds + 0.5 - (seconds + 0.5) % 1

    
    temp = tostring(minutes) .. " : " .. tostring(seconds)
    SetText(Text, temp)
    SetTextOrigin(Text, "MiddleCenter")
end