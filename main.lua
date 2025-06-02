require("input")
require("player")

TICK_PERIOD = 0.016

local tick_timer = TICK_PERIOD

function love.load()
  input_init()
  player:init()
end

function love.update(dt)
  -- fixed time step
  tick_timer = tick_timer + dt
  while tick_timer >= TICK_PERIOD do
    player:tick()
    tick_timer = tick_timer - TICK_PERIOD
  end
end

function love.draw()
  love.graphics.push()
  player:draw()
  love.graphics.pop()
end

function love.keypressed(key, scancode, isrepeat)
  input_on_key_pressed(key, scancode, isrepeat)
end

function love.keyreleased(key, scancode)
  input_on_key_released(key, scancode)
end