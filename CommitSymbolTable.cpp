#include "CommitSymbolTable.h"
#include "Commit.h"
#include <string>

using UGit::Commit;
using std::string;

struct Node {
	Node* next;
	string key;
	Commit* value;
};

struct List {
	Node* first;
};

struct UCommitSymbolTable::Dictionary {
	List* list;
};

Node* CreateNode(string key, Commit* value, Node* next) {
	Node* newNode = new Node;
	newNode->key = key;
	newNode->value = value;
	newNode->next = next;
	return newNode;
}

UCommitSymbolTable::Dictionary* UCommitSymbolTable::Create() {
    Dictionary* dictionary = new Dictionary;
    dictionary->list = new List;
    dictionary->list->first = nullptr;
    return dictionary;
}

void UCommitSymbolTable::AddElement(Dictionary* dictionary, string key, Commit* value) {
	Node* iterator = dictionary->list->first;
	bool elementFound = false;

	while (iterator != NULL && !elementFound) {
		if (key.compare(iterator->key) == 0)
		{
			iterator->value = value;
			elementFound = true;
		}

		iterator = iterator->next;
	}

	if (!elementFound) {
		dictionary->list->first = CreateNode(key, value, dictionary->list->first);
	}
}

Commit* UCommitSymbolTable::GetValue(Dictionary* dictionary, string key) {
    Node* iterator = dictionary->list->first;
    while (iterator != nullptr) {
        if (key.compare(iterator->key) == 0) {
            return iterator->value;
        }
        iterator = iterator->next;
    }
    return nullptr;
}

bool UCommitSymbolTable::IsKeyIncluded(Dictionary* dictionary, string key) {
    Node* iterator = dictionary->list->first;
    while (iterator != NULL) {
        if (key.compare(iterator->key) == 0) {
            return true;
        }
        iterator = iterator->next;
    }
    return false;
}

void UCommitSymbolTable::Destroy(Dictionary* dictionary) {
    Node* iterator = dictionary->list->first;
    while (iterator != NULL) {
        Node* nodeToRemove = iterator;
        iterator = iterator->next;
        delete nodeToRemove;
    }
    delete dictionary->list;
    delete dictionary;
}

