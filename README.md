# Replace Header PowerShell Script

📝 This is a PowerShell script that updates the header of all CSV files in a specified folder with a specified date. If no date is provided, the current system date is used. The script uses a separate executable file called "replaceheader.exe" to replace the header of each CSV file which is written in C.

## Parameters

🔧 The script takes two parameters:

- `folder`: The folder path where the CSV files are located.
- `date`: The date to use in the updated header and should be in the format 'yyyy-MM-dd'. If no date is provided, the current system date is used.

📂 The script requires the "replaceheader.exe" executable file to be located in the same directory as the script file.

## Usage

🚀 To use this script, run it with two arguments: the folder path and the date in the format 'yyyy-MM-dd'. For example:

```
./updateheader.exe /home/user/Documents/CSVs 2022-01-01
```

📝 The script logs the update time and file names in a transcript file called "Log.txt".

## Error Handling

🚨 The script checks for the following errors:

- If no folder path argument is provided, the script returns an error.
- If an invalid date argument is provided, the script returns an error.

## License

📜 This script is licensed under the MIT License. See the LICENSE file for details.
