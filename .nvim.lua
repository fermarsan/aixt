vim.filetype.add({
  extension = {
    nxc = 'c',
  },
})

vim.api.nvim_create_user_command('Compilar', function(args)
  local cmd = "gcc " .. vim.fn.expand('%:p') .. " -o " .. vim.fn.expand('%:r') -- Compila el archivo actual
  local handle = io.popen(cmd)
  local result = handle:read("*a")
  handle:close()
  if result then
    vim.api.nvim_echo({{ "Salida del compilador:\n" .. result, "ErrorMsg" }}, true, {})
  else
    vim.api.nvim_echo({{ "Compilación exitosa.", "MoreMsg" }}, true, {})
  end
end, {nargs = 0})
