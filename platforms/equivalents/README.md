## **Aixt** API for NXC Language

All the functions in **Aixt** keep the same name of the **NXC** for ease. The only difference is **Aixt** uses _snake\_case_ instead of _CamelCase_. For this, a _YAML_ setup file is used for the translation between both cases. The next code shows an extract of the `equivalents.yaml` file:

```yaml
out_a:      OUT_A
out_b:      OUT_B
.
.
.
on_reverse: OnRev
on_rev:     OnRev
on_forward: OnFwd
on_fwd:     OnFwd
.
.
.
```

Left side shows the API functions in **Aixt** and right side the original **NXC** API functions.