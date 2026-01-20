# TASKER

## What Is Tasker?

Tasker is a custom mind-dump / note-jotting program that can be used to write down any task you want to keep stored somewhere on your device.


## Base Usage

### Create A New Task Log:

`tskr init <name>`
This will create a new log. After running the command it will automatically open up the file via either nano or nvim for you to edit.


### Edit A Task Log:

`tskr edit <log>`
Opens up the specified task log for you to edit.


### Read A Task Log:

The tasker read command has several arguments.

- `tskr read <log>`: Outputs every entry in the specified log
- `tskr read <log> -i <entry_id>`: Shows only the index you provide (can provide multiple via `i1,i2`)
- `tskr read <log> -h <header>`: Shows only the results for entries with the specified header (can provide multiple via `h1,h2`)


### Mark A Task Log Entry's Status:

`tskr mark <log> <status>` 

The following status are supported currently:
- Completed   : 0
- In Progress : 1
- Not Started : 2


### Remove A Task Log

`tskr remove <log>`
You will be prompted with a confirmation message.


### Remove An Entry:

There's several methods to remove entires from a task log:
- `tskr rmentry <log> -i <id>`: Removes the specified UUID (can provide multiple via `i1,i2`)
- `tskr rmentry <log> -h <header>`: Removes the specified header (can provide multiple via `h1, h2`)

Be mindful that if multiple entries are provided, it will prompt you with a confirmation message.


## Configuration

All Tasker configurations are stored in `.tskr.settings`. You can edit this directly through Tasker via `tskr edit settings`.


### Default Editor:
Changes which text editor is opened when running `tskr edit`.
`tskr config -editor <nano || nvim || "path/to/editor">`


### Toggle Confirmation Message:

`tskr config -confirm <True || False || 0 || 1>`


### Set Provided Arguments Count For Confirmation Message:

Keep in mind that setting it to 0 will **ALWAYS** cause a confirmation message. If you have toggled the confirmation message off, then no matter what you provide here the confirmation message will **NEVER** show.
`tskr config -confirmCount <int>`


## Pseudonyms & Command Configuration

You can edit the default commands to include your preferred pseudonyms for both commands and arguments (with some leniency) via `tskr edit .cmd.settings`.


### Default Pseudonyms For Commands:

- `config` : `cfg`
- `edit`   : `edt`
- *Will Add More Later..*


### Default Pseudonyms For Arguments:

- `-i`  : `-id`
- `-h`  : `-header`
- *Will Add More Later..*


---

-# More To Come!!!

***Much Love, Ivy <3***
