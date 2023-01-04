## **Aixt** API for NXC Language

All the functions in **Aixt** keep the same name of the **NXC** for ease. The only difference is **Aixt** uses _snake\_case_ instead of _CamelCase_. For this, a YAML setup file is used for the translation between both cases. The next code shows an extract of the the `equivalents.yaml` file:

```yaml
on_rev: OnRev
on_fwd: OnFwd
.
.
.
out_A:  OUT_A
out_B:  OUT_B
.
.
.
```