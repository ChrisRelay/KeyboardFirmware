#ifndef LAYOUT_H
#define LAYOUT_H

//Row and column count
#define rows 5
#define columns 14

//Pin numbers
//GPIO_A
uint8 row[rows] = {0, 1, 2, 3, 4};
//GPIO_B
uint8 column[columns] = {0, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

//Key map
unsigned char keymap[rows][columns] = {
  {KEYBRD_TILDA       , KEYBRD_1            , KEYBRD_2      , KEYBRD_3      , KEYBRD_4      , KEYBRD_5      , KEYBRD_6          , KEYBRD_7      , KEYBRD_8      , KEYBRD_9        , KEYBRD_0         , KEYBRD_MINUS        , KEYBRD_EQUALS       , KEYBRD_BACKSPACE },
  {KEYBRD_TAB         , KEYBRD_Q            , KEYBRD_W      , KEYBRD_E      , KEYBRD_R      , KEYBRD_T      , KEYBRD_Y          , KEYBRD_U      , KEYBRD_I      , KEYBRD_O        , KEYBRD_P         , KEYBRD_LBRACKET     , KEYBRD_RBRACKET     , KEYBRD_BACKSLASH },
  {KEYBRD_CAPSLOCK    , KEYBRD_A            , KEYBRD_S      , KEYBRD_D      , KEYBRD_F      , KEYBRD_G      , KEYBRD_H          , KEYBRD_J      , KEYBRD_K      , KEYBRD_L        , KEYBRD_COLON     , KEYBRD_AT           , 0                   , KEYBRD_RETURN    },
  {KEYBRD_SHIFT       , KEYBRD_Z            , KEYBRD_X      , KEYBRD_C      , KEYBRD_V      , KEYBRD_B      , KEYBRD_N          , KEYBRD_M      , KEYBRD_COMMA  , KEYBRD_PERIOD   , KEYBRD_SLASH     , 0                   , 0                   , KEYBRD_RSHIFT    },
  {KEYBRD_CTRL        , KEYBRD_WIN          , KEYBRD_ALT    , 0             , 0             , 0             , KEYBRD_SPACE      , 0             , 0             , 0               , KEYBRD_RALT      , KEYBRD_RWIN         , 0                   , KEYBRD_RCTRL     },
};

#endif
