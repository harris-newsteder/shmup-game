
INPUT_UP     = 0
INPUT_DOWN   = 1
INPUT_LEFT   = 2
INPUT_RIGHT  = 3
INPUT_A      = 4
INPUT_B      = 5
INPUT_X      = 6
INPUT_Y      = 7
INPUT_LBUMP  = 8
INPUT_RBUMP  = 9
INPUT_START  = 10
INPUT_SELECT = 11

local callbacks = {
  pressed = {},
  released = {}
}

function input_init()

end

function input_on_key_pressed(key, scancode, isrepeat)
  for i, v in ipairs(callbacks.pressed) do
    v()
  end
end

function input_on_key_released(key, scancode)
  for i, v in ipairs(callbacks.released) do
    v()
  end
end

function input_register_pressed_callback(func, ctx)
  table.insert(callbacks.pressed, func)
end

function input_register_released_callback(func, ctx)
  table.insert(callbacks.released, func)
end
