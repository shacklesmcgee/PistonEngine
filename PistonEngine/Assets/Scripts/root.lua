gameTimer = 125
screenWidth = 512
screenHeight = 512
timeOfLastSpawn = 125
numOfSpawns = 1

function Start(args)
    height = GetTextHeight(Text)
    SetLocation(Transform, screenWidth/2, height/2)
    SetTextOrigin(Text, "MiddleCenter")
end

function Update(dt)

    gameTimer = gameTimer - (dt/1)
    
    if(gameTimer < timeOfLastSpawn - 9) then
	timeOfLastSpawn = gameTimer

	enemy = {
                name = "enemy",
    	        position = {x = 0, y = 32},
	        rotation = {angle = 0.0, x = 0.0, y = 0.0}, 
                scale = {x = 1.0, y = 1.0},
	        graphics = {name = "enemy", texture = "../../Assets/Textures/enemy.png", animated = true, textureX = 0, textureY = 32, textureWidth = 32, textureHeight = 32, frameTime = 0.1, looping = true}, 
	        script = {location = "../../Assets/Scripts/enemy.lua", args = {}},    
	        rigidBody = {mass = 1.0, restitution = 1.0, obeysGravity = false}
                }

	--for i = 1, numOfSpawns do
	    Create(GameObject, enemy)
	--end
	numOfSpawns = numOfSpawns + 1
    end

    seconds = gameTimer % 60
    minutes = (gameTimer - seconds) / 60

    minutes = math.floor(minutes+0.5)
    seconds = math.floor(seconds+0.5)

    temp = tostring(minutes) .. " : " .. tostring(seconds)
    SetText(Text, temp)
    SetTextOrigin(Text, "MiddleCenter")
end