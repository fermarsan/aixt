# module nxt.lcd


## Contents
- [Constants](#Constants)
- [clear](#clear)
- [clear_line](#clear_line)
- [contrast](#contrast)
- [draw_circle](#draw_circle)
- [draw_ellipse](#draw_ellipse)
- [draw_line](#draw_line)
- [draw_point](#draw_point)
- [draw_rect](#draw_rect)
- [into_range](#into_range)
- [move_to](#move_to)
- [print](#print)
- [println](#println)
- [reset](#reset)
- [set_contrast](#set_contrast)
- [write_num](#write_num)
- [write_text](#write_text)

## Constants
```v
const x_max = i8(90)
```

[[Return to contents]](#Contents)

```v
const y_max = i8(56)
```

[[Return to contents]](#Contents)

```v
const line_8 = 0
```

Line numbers for use with DrawText system function.

[[Return to contents]](#Contents)

```v
const line_7 = 8
```

[[Return to contents]](#Contents)

```v
const line_6 = 16
```

[[Return to contents]](#Contents)

```v
const line_5 = 24
```

[[Return to contents]](#Contents)

```v
const line_4 = 32
```

[[Return to contents]](#Contents)

```v
const line_3 = 40
```

[[Return to contents]](#Contents)

```v
const line_2 = 48
```

[[Return to contents]](#Contents)

```v
const line_1 = 56
```

[[Return to contents]](#Contents)

```v
const text_line_1 = 0
```

Constants that are for use with getting/setting display data.

[[Return to contents]](#Contents)

```v
const text_line_2 = 1
```

[[Return to contents]](#Contents)

```v
const text_line_3 = 2
```

[[Return to contents]](#Contents)

```v
const text_line_4 = 3
```

[[Return to contents]](#Contents)

```v
const text_line_5 = 4
```

[[Return to contents]](#Contents)

```v
const text_line_6 = 5
```

[[Return to contents]](#Contents)

```v
const text_line_7 = 6
```

[[Return to contents]](#Contents)

```v
const text_line_8 = 7
```

[[Return to contents]](#Contents)

```v
const text_lines = 8
```

[[Return to contents]](#Contents)

## clear
```v
fn clear()
```

[[Return to contents]](#Contents)

## clear_line
```v
fn clear_line(args ...any)
```

[[Return to contents]](#Contents)

## contrast
```v
fn contrast() u8
```

[[Return to contents]](#Contents)

## draw_circle
```v
fn draw_circle(args ...any) i8
```

[[Return to contents]](#Contents)

## draw_ellipse
```v
fn draw_ellipse(args ...any) i8
```

[[Return to contents]](#Contents)

## draw_line
```v
fn draw_line(args ...any) i8
```

[[Return to contents]](#Contents)

## draw_point
```v
fn draw_point(args ...any) i8
```

[[Return to contents]](#Contents)

## draw_rect
```v
fn draw_rect(args ...any) i8
```

[[Return to contents]](#Contents)

## into_range
```v
fn into_range(num i8, max i8, min i8) i8
```

[[Return to contents]](#Contents)

## move_to
```v
fn move_to(x i8, y i8)
```

[[Return to contents]](#Contents)

## print
```v
fn print(msg string)
```

[[Return to contents]](#Contents)

## println
```v
fn println(msg string)
```

[[Return to contents]](#Contents)

## reset
```v
fn reset()
```

[[Return to contents]](#Contents)

## set_contrast
```v
fn set_contrast(args ...any)
```

[[Return to contents]](#Contents)

## write_num
```v
fn write_num(args ...any) i8
```

[[Return to contents]](#Contents)

## write_text
```v
fn write_text(args ...any) i8
```

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 18:05:26
