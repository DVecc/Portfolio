# Vincent Del Vecchio
# File: CS210_Starter_PY_Code
# Description:
#   Collection of functions that obtains a list of items and the frequency of their purchase from a .txt file
#   to be used in an acoompanying C++ file that handles user input
import re
import string

# Produce a list of all items purchased in a given day along with the number of times each item was purchased.
def PrintAllItems():
    itemDict = itemCounter() # Dictionary containing items bought and the number bought during the day read from file returned from the called function

    print("\nItem List:")
    # Print each item and the number bought from the dictionary
    for x, y in itemDict.items():
        print (x,y)

# Returns a dicionary of items read from a file as keys with their frequnecies as the value
def itemCounter():
    itemDict = {} # Empty dictionary to hold items and quanitites to be read from file
    itemFile = open("CS210_Project_Three_Input_File.txt","rt") # Open item file

    for line in itemFile: # Loop through each line in the file
        item = str.strip(itemFile.readline()) # read line from file
        if item in itemDict: # if item is already in the dictionary update quantity by 1
            itemDict[item] = itemDict[item] + 1
        else: # item is not in the dictionary, create an entry with an initial quantity of 1
            itemDict[item] = 1

    itemFile.close() # close the file
    return itemDict # return the itemDictonary

# Returns the frequency of an item passed into the function, if item is not in dictionary returns 0
def getItemFrequency(itemName):
    itemDict = itemCounter() # Dictionary containing items bought and the number bought during the day read from file returned from the called function

    if itemName.capitalize() in itemDict: # if item is in dictionary return it's value otherwise return 0, capitalizes first letter to match textfile input
        return itemDict[itemName.capitalize()]
    else:
        return 0

# Records the list of itmes and their frequencies to a .dat file creating it if it doesn't already exist
def createFrequencyFile():
    itemDict = itemCounter() # Dictionary containing items bought and the number bought during the day read from file returned from the called function

    frequencyFile = open("frequency.dat", "w+") # opens file for writing, creating one if it does not already exist

    # Writes each item and it's frequency as a line to the file
    for x,y in itemDict.items():
        frequencyFile.write("%s %s\n" %(x,y))