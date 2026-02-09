# Documentation from code

For generating the documentation from the code, it is necessary to follow these steps:

- change the name of the file `api/v.mod.temp` to `api/v.mod.temp`
- inside the `aixt` root directory run the commands:
  - `v doc -m -f html -o ./docs/api_html -readme ./api` for the HTML version
  - `v doc -m -f md -o ./docs/api_markdown ./api` for the Markdown version
- change back the file vmod file to `api/v.mod.temp`