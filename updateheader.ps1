<#

.SYNOPSIS
Updates the header of all CSV files in a specified folder with a specified date.
Author - PRIYA RANJAN KUMAR 
Date - 2021-10-20

.DESCRIPTION
This script updates the header of all CSV files in a specified folder with a specified date. If no date is provided, the current system date is used. The script uses a separate executable file called "replaceheader.exe" to replace the header of each CSV file.

.PARAMETER folder
The folder path where the CSV files are located.

.PARAMETER date
The date to use in the updated header. Should be in the format 'yyyy-MM-dd'.

.EXAMPLE
./updateheSYNOPSISader.ps1 /home/user/Documents/CSVs 2022-01-01
Updates the header of all CSV files in the /home/user/Documents/CSVs folder with the date '2022-01-01'.

.NOTES
This script requires the "replaceheader.exe" executable file to be located in the same directory as the script file.
#>
Start-Transcript "Log.txt"
    $swm = new-object System.Diagnostics.Stopwatch
    $swm.Start()
# Check if a folder path argument was provided
if ($args[0]) {
    # If a folder path argument was provided, use it
    $folder = $args[0]
}
else {
    # If no folder path argument was provided, prompt the user for a folder path
    Write-Host "Error: No argument provided."
    Stop-Transcript
    return
}
Write-Host "Folder path: $folder"
# Check if a date argument was provided
if ($args[1]) {
    # If a date argument was provided, use it
    $dateString = $args[1].ToString()
    $format = "yyyy-MM-dd"
    $date = [DateTime]::MinValue
    if ([DateTime]::TryParseExact($dateString, $format, $null, [System.Globalization.DateTimeStyles]::None, [ref]$date)) {
        # If the date is valid, use it
        Write-Host "Valid date: $($date.ToString($format))"
    }
    else {
        # If the date is invalid, stop the script
        Write-Host "Error: Invalid date argument provided. Please use the format 'yyyy-MM-dd'."
        Stop-Transcript
        return
    }
}
else {
    # If no date argument was provided, use the current system date
    
    $date = Get-Date
    $dateString = $date.ToString("yyyy-MM-dd")
    Write-Host "No date argument was provided, using the current system date." $dateString
}

$files = Get-ChildItem -Path $folder -Filter "*.csv"
# Iterate over the files in the folder

foreach ($file in $files) {
    $sw = new-object System.Diagnostics.Stopwatch
    $sw.Start()
    Write-Host $file.FullName
    & "./replaceheader.exe" $file.FullName $dateString
    $sw.Stop()
    Write-Host "Header updated in " $sw.Elapsed.TotalSeconds "seconds"  $file.FullName
}
 $swm.Stop()
    Write-Host "Total update time " $swm.Elapsed.TotalSeconds "seconds"
Stop-Transcript
