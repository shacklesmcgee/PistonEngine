gameTimer = 125
screenWidth = 512
screenHeight = 512

function Start(args)
    height = GetTextHeight(Text)
    SetLocation(Transform, screenWidth/2, height/2)
    SetTextOrigin(Text, "MiddleCenter")
end

function Update(dt)

    gameTimer = gameTimer - (dt/1)
    
    seconds = gameTimer % 60
    minutes = (gameTimer - seconds) / 60

    minutes = math.floor(minutes+0.5)
    seconds = math.floor(seconds+0.5)

    temp = tostring(minutes) .. " : " .. tostring(seconds)
    SetText(Text, temp)
    SetTextOrigin(Text, "MiddleCenter")
end
