gameTimer = 120
screenWidth = 512
screenHeight = 512
alive = true

function Start(args)
    height = GetTextHeight(Text)
    SetLocation(Transform, screenWidth/2, height/2)
    SetTextOrigin(Text, "MiddleCenter")
    print(args[1])
    print(args[2])
end

function Update(dt)

    if (alive) then
        gameTimer = gameTimer - (dt/1)
                
        if (gameTimer <= 0) then
            GameOver()
            return
        end

        seconds = gameTimer % 60
        minutes = (gameTimer - seconds) / 60

        minutes = math.floor(minutes+0.5)
        seconds = math.floor(seconds+0.5)

        temp = tostring(minutes) .. " : " .. tostring(seconds)
        SetText(Text, temp)
        SetTextOrigin(Text, "MiddleCenter")
    end
end

function GameOver()
    temp = "YOU WON!"
    SetText(Text, temp)
    SetTextOrigin(Text, "MiddleCenter")
    alive = false
end


function Test()
    print("works")
end