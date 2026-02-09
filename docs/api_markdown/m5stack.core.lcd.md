# module m5stack.core.lcd


## Contents
- [Constants](#Constants)
- [bitmap](#bitmap)
- [bmp_file](#bmp_file)
- [brightness](#brightness)
- [centre_string](#centre_string)
- [char](#char)
- [circle](#circle)
- [circle_helper](#circle_helper)
- [clear](#clear)
- [cursor](#cursor)
- [draw_line](#draw_line)
- [draw_pixel](#draw_pixel)
- [fill_circle](#fill_circle)
- [fill_circle_helper](#fill_circle_helper)
- [fill_rect](#fill_rect)
- [fill_round_rect](#fill_round_rect)
- [fill_screen](#fill_screen)
- [fill_triangle](#fill_triangle)
- [height](#height)
- [jpg](#jpg)
- [jpg_file](#jpg_file)
- [print](#print)
- [println](#println)
- [rect](#rect)
- [rgb_bitmap](#rgb_bitmap)
- [right_string](#right_string)
- [round_rect](#round_rect)
- [text_color](#text_color)
- [text_color_bg](#text_color_bg)
- [text_size](#text_size)
- [text_wrap](#text_wrap)
- [triangle](#triangle)
- [width](#width)

## Constants
```v
const red = u32(C.RED)
```

[[Return to contents]](#Contents)

```v
const green = u32(C.GREEN)
```

[[Return to contents]](#Contents)

```v
const blue = u32(C.BLUE)
```

[[Return to contents]](#Contents)

```v
const yellow = u32(C.YELLOW)
```

[[Return to contents]](#Contents)

```v
const cyan = u32(C.CYAN)
```

[[Return to contents]](#Contents)

```v
const magenta = u32(C.MAGENTA)
```

[[Return to contents]](#Contents)

```v
const white = u32(C.WHITE)
```

[[Return to contents]](#Contents)

```v
const black = u32(C.BLACK)
```

[[Return to contents]](#Contents)

```v
const gray = u32(C.GRAY)
```

[[Return to contents]](#Contents)

## bitmap
```v
fn bitmap(x int, y int, bitmap []u8, w int, h int, color u32)
```

[[Return to contents]](#Contents)

## bmp_file
```v
fn bmp_file(fs any, path string, x u32, y u32)
```

[[Return to contents]](#Contents)

## brightness
```v
fn brightness(brightness u8)
```

[[Return to contents]](#Contents)

## centre_string
```v
fn centre_string(str string, dx int, poy int, font int)
```

[[Return to contents]](#Contents)

## char
```v
fn char(x u32, y u32, c u8, color u32, bg u32, size u8)
```

[[Return to contents]](#Contents)

## circle
```v
fn circle(x0 int, y0 int, r int, color u32)
```

[[Return to contents]](#Contents)

## circle_helper
```v
fn circle_helper(x0 int, y0 int, r int, cornername u8, color u32)
```

[[Return to contents]](#Contents)

## clear
```v
fn clear(color u32)
```

[[Return to contents]](#Contents)

## cursor
```v
fn cursor(x0 u32, y0 u32)
```

[[Return to contents]](#Contents)

## draw_line
```v
fn draw_line(x0 int, y0 int, x1 int, y1 int, color u32)
```

[[Return to contents]](#Contents)

## draw_pixel
```v
fn draw_pixel(x int, y int, color u32)
```

[[Return to contents]](#Contents)

## fill_circle
```v
fn fill_circle(x0 int, y0 int, r int, color u32)
```

[[Return to contents]](#Contents)

## fill_circle_helper
```v
fn fill_circle_helper(x0 int, y0 int, r int, cornername u8, delta int, color u32)
```

[[Return to contents]](#Contents)

## fill_rect
```v
fn fill_rect(x int, y int, w int, h int, color u32)
```

[[Return to contents]](#Contents)

## fill_round_rect
```v
fn fill_round_rect(x0 int, y0 int, w int, h int, radius int, color u32)
```

[[Return to contents]](#Contents)

## fill_screen
```v
fn fill_screen(color u32)
```

[[Return to contents]](#Contents)

## fill_triangle
```v
fn fill_triangle(x0 int, y0 int, x1 int, y1 int, x2 int, y2 int, color u32)
```

[[Return to contents]](#Contents)

## height
```v
fn height() i16
```

[[Return to contents]](#Contents)

## jpg
```v
fn jpg(jpg_data string, jpg_len any, x u32, y u32)
```

[[Return to contents]](#Contents)

## jpg_file
```v
fn jpg_file(fs any, path string, x u32, y u32)
```

[[Return to contents]](#Contents)

## print
```v
fn print(str string)
```

[[Return to contents]](#Contents)

## println
```v
fn println(str string)
```

[[Return to contents]](#Contents)

## rect
```v
fn rect(x int, y int, w int, h int, color u32)
```

[[Return to contents]](#Contents)

## rgb_bitmap
```v
fn rgb_bitmap(x int, y int, bitmap []u16, w int, h int)
```

[[Return to contents]](#Contents)

## right_string
```v
fn right_string(str string, dx int, poy int, font int)
```

[[Return to contents]](#Contents)

## round_rect
```v
fn round_rect(x0 int, y0 int, w int, h int, radius int, color u32)
```

[[Return to contents]](#Contents)

## text_color
```v
fn text_color(color u32)
```

[[Return to contents]](#Contents)

## text_color_bg
```v
fn text_color_bg(color u32, bgcolor u32)
```

[[Return to contents]](#Contents)

## text_size
```v
fn text_size(size u8)
```

[[Return to contents]](#Contents)

## text_wrap
```v
fn text_wrap(w bool)
```

[[Return to contents]](#Contents)

## triangle
```v
fn triangle(x0 int, y0 int, x1 int, y1 int, x2 int, y2 int, color u32)
```

[[Return to contents]](#Contents)

## width
```v
fn width() i16
```

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
