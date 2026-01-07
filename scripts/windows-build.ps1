$RUN = $false
$RUNCMAKE = $false

# Parse $args
foreach ($arg in $args) {
  if ($arg.StartsWith("--")) {
    switch ($arg) {
      "--run" { $RUN = $true }
      "--run_cmake" { $RUNCMAKE = $true }
      default { Write-Host "Unknown argument: $arg" }
    }
  }
  elseif ($arg.StartsWith("-")) {
    $shortFlags = $arg.Substring(1).ToCharArray()
    foreach ($ch in $shortFlags) {
      switch ($ch) {
        "r" { $RUN = $true }
        "c" { $RUNCMAKE = $true }
        default { Write-Host "Unknown short flag: -$ch" }
      }
    }
  }
  else {
    Write-Host "Unknown argument: $arg"
  }
}

$sloc = Get-Location
Set-Location $PSScriptRoot
Set-Location ../build

# Build steps array in order
$steps = @()
if ($RUNCMAKE) { $steps += "cmake" }
$steps += "make"
if ($RUN) { $steps += "the program" }

# Format nicely
switch ($steps.Count) {
  0 { $str = "" }
  1 { $str = $steps[0] }
  2 { $str = "$($steps[0]) and $($steps[1])" }
  default { $str = ($steps[0..($steps.Count - 2)] -join ", ") + ", and " + $steps[-1] }
}

Write-Host "Running: $str"

# Run commands
if ($RUNCMAKE) {
  Write-Host "Running cmake .."
  & cmake .. | Out-Host
}

Write-Host "Running make"
& make | Out-Host

if ($RUN) {
  Write-Host "Running VoltRaylib_Test.exe"
  & ./VoltRaylib_Test.exe | Out-Host
}

Set-Location $sloc
