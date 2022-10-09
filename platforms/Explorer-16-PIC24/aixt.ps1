param ( 
    [Parameter(Mandatory=$True)][string]$file
)

Write-Host "Transpiling" $file
Write-Host ""
python ../../base/aixt.py $file