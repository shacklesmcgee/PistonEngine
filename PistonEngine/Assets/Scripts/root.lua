gameTimer = 35
screenWidth = 512
screenHeight = 512
alive = true
gameWon = false

function Start(args)
    height = GetTextHeight(Text)
    SetLocation(Transform, screenWidth/2, 20)
    SetTextOrigin(Text, "MiddleCenter")
end

function Update(dt)

    if (alive) then
        gameTimer = gameTimer - (dt/1)
                
        if (gameTimer <= 0) then
            gameWon = true
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
    if (gameWon) then
        temp = "YOU WON!"
        SetText(Text, temp)
        SetTextOrigin(Text, "MiddleCenter")
        alive = false

    else
        temp = "YOU DIED!"
        SetText(Text, temp)
        SetTextOrigin(Text, "MiddleCenter")
        alive = false
    end
    PauseGame(GameObject)
end


function Receive(args)
    if (args[1] == "dead") then
        GameOver()
    end
end