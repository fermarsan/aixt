import watch
import time
import lv

watch.start()

text := lv.label_create(lv.scr_act())
lv.label_set_text(text, "T-Watch")
lv.obj_align(text, lv.align_center, 0, 0)

for {
    lv.task_handler()
    time.sleep(5)
}