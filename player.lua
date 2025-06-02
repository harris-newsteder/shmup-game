PLAYER_CONDITION_NORMAL = 0
PLAYER_CONDITION_HIT = 1
PLAYER_CONDITION_INJURED = 2
PLAYER_CONDITION_RESTORING = 3
PLAYER_CONDITION_CRITICAL = 4

player = {}

player.x = 0
player.y = 0

player.pwep_active = false
player.pwep_delay = 3
player.pwep_max = 20
player.pwep_counter = 0
player.pwep_timer = 0

player.condition = PLAYER_CONDITION_NORMAL
player.health = 6

player.v_speed = 1
player.h_speed = 2

function player:init()
  input_register_pressed_callback(self.on_input_pressed)
  input_register_released_callback(self.on_input_released)
end

function player:tick()
  if self.pwep_active then
    self.pwep_timer = self.pwep_timer + 1

    if self.pwep_timer >= self.pwep_delay then
      -- fire shot
      self.pwep_counter = self.pwep_counter + 1
      print("shot " .. self.pwep_counter)
      self.pwep_timer = 0
    end
  end
end

function player:draw()
  love.graphics.push()
  love.graphics.translate(self.x, self.y)
  love.graphics.rectangle("fill", 0, 0, 32, 16)
  love.graphics.pop()
end

function player:on_input_pressed(input)
  self.pwep_active = true
end

function player:on_input_released(input)
  self.pwep_active = false
end