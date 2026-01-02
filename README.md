# 📌 **Inverted Search Project**

## 🧠 **Overview**

This project implements an **Inverted Search (Inverted Index)** system in **C**.
An inverted index maps **words to the files in which they appear**, allowing fast and efficient searching across multiple text files.

Instead of scanning every file during a search, the program builds an index once and uses it to retrieve results instantly.

---

## 🚀 **Features**

✔️ Create an inverted index from multiple text files
✔️ Store each word with:

* File count
* Word count per file
  ✔️ Search for a word and display matching files
  ✔️ Save the database to a file
  ✔️ Load and reuse the saved database
  ✔️ Hash-based indexing for faster access

---

## 📁 **Project Structure**

```
invertedsearch_src/
├── main.c
├── create_database.c
├── search_database.c
├── save_database.c
├── display_database.c
├── inverted_search.h
├── sample_files/
│   ├── file1.txt
│   ├── file2.txt
│   └── file3.txt
└── README.md
```

---

## 📘 **Data Structures Used**

### 🔹 Hash Table

* Size: **28**

  * A–Z → 0–25
  * Digits → 26
  * Special characters → 27

### 🔹 Main Node

Stores:

* Word
* File count
* Pointer to sub-node list

### 🔹 Sub Node

Stores:

* Filename
* Word count
* Link to next file

---

## 🧩 **Functional Modules**

### 1️⃣ **Validate Arguments**

* Checks command-line arguments
* Ensures only `.txt` files are accepted
* Stores filenames in a linked list

### 2️⃣ **Create Database**

* Reads each file word by word
* Calculates hash index
* Creates main node if word is new
* Updates sub-node if word already exists

### 3️⃣ **Search Database**

* Takes a word from the user
* Finds its hash index
* Displays:

  * File count
  * Word count
  * Filenames

### 4️⃣ **Display Database**

* Displays the entire inverted index
* Useful for debugging and verification

### 5️⃣ **Save Database**

* Writes the index into a file (`output.txt`)
* Format:

  ```
  #index;word;filecount;wordcount;filename;...#
  ```

---

## ⚙️ **Compilation (Without Makefile)**

Use **gcc directly**:

```sh
gcc main.c create_database.c search_database.c save_database.c display_database.c -o inverted_search
```

---

## ▶️ **Execution**

```sh
./inverted_search file1.txt file2.txt file3.txt
```

---

## 🔍 **Sample Search Output**

```
Enter the word to Search: data

Filecount   Word           Word Count        Filename
------------------------------------------------------
2           data           5                 file1.txt
                            3                 file2.txt
```

---

## 💡 **Algorithm Flow**

1. Read file names from command line
2. Validate file extensions
3. Create inverted index using hash table
4. Perform operations:

   * Search
   * Display
   * Save
5. Exit gracefully

---

## 🧠 **Advantages**

✔ Fast search
✔ Efficient memory usage
✔ Scalable for multiple files
✔ Avoids repeated file scanning

---

## 🚀 **Future Enhancements**

* Phrase searching
* Case-insensitive search
* Stop-word removal
* Load database from saved file
* Dynamic hash resizing

---

## 📚 **Conclusion**

This project demonstrates the **core working of search engines** using fundamental **data structures** like hash tables and linked lists. It is an excellent example of applying DSA concepts to real-world problems.

