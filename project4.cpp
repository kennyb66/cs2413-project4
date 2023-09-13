// Project 4
// CS 2413 Data Structures
// Spring 2023

#include <iostream>
#include <vector> // for array of transactions and array of blockChains
#include <list>   // for blockchain

using namespace std;

class transaction
{
    int tID;          // transaction id
    int fromID;       // source ID
    int fromValue;    // how much funds does the source ID person have? If first time, then initialize with 100 coins
    int toID;         // target ID
    int toValue;      // how much funds does the target ID person have? If first time, then initialize with 100 coins
    int tAmount;      // how much is being transferred
    string timeStamp; // time of the transaction read from the input file

public:
    transaction();                                                                                 // default constructor
    transaction(int temptID, int tempfromID, int temptoID, int temptAmount, string temptimeStamp); // non default constructor - P4: default 100 for from and to values
    int getFromID(); // getter that returns the fromID of a transaction
    int getToID(); // getter that returns the toID of a transaction
    int getAmount(); // getter that returns the amount of a transaction
    int getFromValue(); // getter that returns the fromValue of a transaction
    int getToValue(); // getter that returns the toValue of a transaction
    int getID(); // getter that returns the ID of a transaction
    string getTimeStamp(); // getter that returns the timestamp of a transaction
    void displayTransaction(); // display method to display a transaction
    void setFromValue(int newValue); // setter that sets the fromValue of a transaction with the newValue parameter
    void setToValue(int newValue); // setter that sets the toValue of a transaction with the newValue parameter
};

transaction::transaction() { // default constructor for transaction class
    tID = 100; // initializing tID with 100
    fromID = 100; // initializing fromID with 100
    toID = 100; // initializing toID with 100
    tAmount = 100; // initializing tAmount with 100
    timeStamp = "100"; // initializing timestamp with 100
    fromValue = 100; // initializing fromValue with 100
    toValue = 100; // initializing toValue with 100
}
transaction::transaction(int temptID, int tempfromID, int temptoID, int temptAmount, string temptimeStamp) // non-default constructor for transaction class
{
    tID = temptID; // initializing tID with the parameter temptID
    fromID = tempfromID; // initializing fromID with the parameter tempfromID
    toID = temptoID; // initializing toID with the parameter temptoID
    tAmount = temptAmount; // initializing tAmount with the parameter temptAmount
    timeStamp = temptimeStamp; // initializing timeStamp with the parameter temptimeStamp
    fromValue = 100; // initializing fromValue with 100
    toValue = 100; // initializing toValue with 100
}
void transaction::setFromValue(int newValue) { // setter for the fromValue of a transaction
    fromValue = newValue; // assigning the fromValue of a transaction with the updated fromValue newValue
}
void transaction::setToValue(int newValue) { // setter for the toValue of a transaction
    toValue = newValue; // assigning the toValue of a transaction with the updated toValue newValue
}
int transaction::getID() { // getter that returns the ID of a transaction
    return tID; // returning the ID
}
void transaction::displayTransaction() // display method to display a transaction
{
    cout << tID << " " << fromID << " " << fromValue << " " << toID << " " << toValue << " " << tAmount << " " << timeStamp << endl; // displaying the transaction
}
string transaction::getTimeStamp() { // getter that returns the timeStamp of a transaction
    return timeStamp; // returning the timeStamp
}
int transaction::getFromID() { // getter that returns the fromID of a transaction
    return fromID; // returning the fromID
}
int transaction::getToID() { // getter that returns the toID of the transaction
    return toID; // returning the toID
}
int transaction::getAmount() { // getter that returns the amount of the transaction
    return tAmount; // returning the amount
}
int transaction::getFromValue() { // getter that returns the fromValue of the transaction
    return fromValue; // returning the fromValue
}
int transaction::getToValue() { // getter that returns the toValue of the transaction
    return toValue; // returning the toValue
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class block
{
    int blockNumber;                   // block number of the current block
    int currentNumTransactions = 0;        // how many transactions are currently in the block
    int maxNumTransactions;            // how many maximum transactions can be in the block
    vector<transaction> bTransactions; // vector of transaction objects
public:
    block();                                 // default constructor
    block(int bNumber, int maxTransactions); // non default constructor
    void insertTransactions(transaction t); // insert method to insert transactions into the block
    int getBlockNumber(); // getter method that returns the block number of a block
    int getNumTransactions(); // getter method that returns the current number of transactions
    int getMaxNumTransactions(); // getter method that returns the max number of transactions for a block
    vector<transaction> getTransactions(); // getter method that returns the bTransactions vector
    void displayBlock(); // display method for a block (calls the transaction display method)
};


block::block(int bNumber, int maxTransactions) { // non-default constructor
    blockNumber = bNumber; // initializing blockNumber
    maxNumTransactions = maxTransactions; // initializing maxNumTransactions
}
int block::getMaxNumTransactions() { // getter method that returns the max number of transactions for a block
    return maxNumTransactions; // returning the max number of transactions for a block
}
int block::getBlockNumber() { // getter method that returns the block number of a block
    return blockNumber; // returning the block number
}
int block::getNumTransactions() { // getter method that returns the current number of transactions
    return currentNumTransactions; // returning the current number of transactions
}
vector<transaction> block::getTransactions() { // getter method that returns the bTransactions vector
    return bTransactions; // returning bTransactions
}

void block::insertTransactions(transaction t) { // insert method to insert transactions into the block
    bTransactions.push_back(t); // inserting the transaction from the parameter into the bTransactions vector
    currentNumTransactions++; // incrementing the current number of transactions every time the insertTransactions method is called
}
void block::displayBlock() { // display method for a block (calls the transaction display method)
    cout << "Block Number: " << getBlockNumber() << " -- Number of Transaction: " << getNumTransactions() << endl; // printing block properties
    for(transaction trn : bTransactions) { // for each loop to display each transaction within a block
        trn.displayTransaction(); // calling the display method from the transaction class
    }
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class blockChain {
    int transactionsPerBlock; // max number of transactions per block
    int currentNumBlocks = 0; // maintain the size of the list/block chain list
    list<block> bChain;   // blockchain as a linked list

public:
    blockChain();          // default constructor
    blockChain(int tPerB); // non default constructor
    void insertTransaction(transaction); // inserting a transaction for a blockChain object
    list<block> getChain(); // getter that returns the bChain List
    void displayChain(); // display method for blockChain that calls the block class display method
    transaction chainSearch(list<block>, transaction, bool); // search method that iterates across each block within a blockChain, which then iterates through each transaction of each block in a blockChain. this method returns the nearest transaction where a fromID or a toID is found
    void calFromOrTo(transaction&, transaction&); // method that determines if a fromID or a toID is found (by calling fromOrTo), then performing the necessary calculations on fromValue and or toValue
    static vector<int> fromOrTo(transaction, transaction); // method that returns a vector<int> object that determines if a fromID and/or a toID is found
    void calc(transaction&); // method that calls the chainSearch method and calFromOrTo to perform the operations on from and to values

};
blockChain::blockChain(int tPerB) { // non default constructor
    block b = block(1, tPerB); // creating a new block with the tPerB parameter and a block number of 1
    currentNumBlocks = 1; // setting currentNumBlocks = 1 as 1 block has been created
    transactionsPerBlock = tPerB; // setting transactionsPerBlock based on tPerB
    bChain.push_back(b); // inserting block b into the bChain
}

vector<int> blockChain::fromOrTo(transaction crnt, transaction prev) { // method that returns a vector<int> object that determines if a fromID and/or a toID is found
    vector<int> v; // initializing v which will be used to determine if a fromID and/or a toID is found
    int value; // value to insert into v
    if(crnt.getFromID() == prev.getFromID()) { // if the current transaction's fromID is equal to a previous transaction's fromID
        value = 1; // associating this case where fromID is equal to a fromID with the int value 1
        v.push_back(value); // inserting the value into v
    }
    if(crnt.getFromID() == prev.getToID()) { // if the current transaction's fromID is equal to a previous transaction's toID
        value = 2; // associating this case where fromID is equal to a toID with the int value 2
        v.push_back(value); // inserting the value into v
    }
    if(crnt.getToID() == prev.getToID()) { // if the current transaction's toID is equal to a previous transaction's toID
        value = 3; // associating this case where toID is equal to a toID with the int value 3
        v.push_back(value); // inserting the value into v
    }
    if(crnt.getToID() == prev.getFromID()) { // if the current transaction's toID is equal to a previous transaction's fromID
        value = 4; // associating this case where toID is equal to a fromID with the int value 4
        v.push_back(value); // inserting the value into v
    }
    return v; // returning the v vector
}
void blockChain::calFromOrTo(transaction& crnt, transaction& prev) { // method that determines if a fromID or a toID is found (by calling fromOrTo), then performing the necessary calculations
    vector<int> v = blockChain::fromOrTo(crnt, prev); // initializing a vector with the return value of the fromOrTo method
    if(v.size() == 2) { // if the size of v is 2, this means that a transaction has both a previous fromID and a previous toID (index 0 of this vector will always be a fromID, index 1 of this vector will always be a toID
        if(v[0] == 1) { // if the fromID that was found has the value 1
            crnt.setFromValue(prev.getFromValue() - prev.getAmount()); // setting the current transaction's fromValue by subtracting the previous transaction's fromValue from the transaction amount
        }
        if(v[0] == 2) { // if the fromID that was found has the value 2
            crnt.setFromValue(prev.getToValue() + prev.getAmount()); // setting the current transaction's fromValue by adding the previous transaction's fromValue with the transaction amount
            }
        }
        if(v[1] == 3) { // if the toID that was found has the value 3
            crnt.setToValue(prev.getToValue() + prev.getAmount()); // setting the current transaction's toValue by adding the previous transaction's toValue with the transaction amount
        }
        if(v[1] == 4) { // if the toID that was found has the value 4
            crnt.setToValue(prev.getFromValue() - prev.getAmount()); // setting the current transaction's toValue by subtracting the previous transaction's fromValue from the transaction amount
        }
    if(v.size() == 1) { // if the size of v is 1, this means that a transaction has a previous fromID or a previous toID, but not both
        if(v[0] == 1) {
            crnt.setFromValue(prev.getFromValue() - prev.getAmount()); // setting the current transaction's fromValue by subtracting the previous transaction's fromValue from the transaction amount
        }
        if(v[0] == 2) {
            crnt.setFromValue(prev.getToValue() + prev.getAmount()); // setting the current transaction's fromValue by adding the previous transaction's toValue with the transaction amount
        }
        if(v[0] == 3) {
            crnt.setToValue(prev.getToValue() + prev.getAmount()); // setting the current transaction's toValue by adding the previous transaction's toValue with the transaction amount
        }
        if(v[0] == 4) {
            crnt.setToValue(prev.getFromValue() - prev.getAmount()); // setting the current transaction's toValue by subtracting the previous transaction's fromValue from the transaction amount
        }
    }
}
void blockChain::calc(transaction& crnt) { // method that calls the chainSearch method and calFromOrTo to perform the operations on from and to values
    transaction t; // initializing a default transaction
    if(chainSearch(bChain, crnt, true).getID() != 100) { // calling chainSearch with the bool parameter being true (true associates with fromIDs), and checking that a fromID was found
        t = chainSearch(bChain, crnt, true); // setting the transaction t to the returned transaction from chainSearch
        calFromOrTo(crnt, t); // calculating the values based on what previous ID was found
    }
    if(chainSearch(bChain, crnt, false).getID() != 100) { // calling chainSearch with the bool parameter being false (false associates with toIDs), and checking that a toID was found
        t = chainSearch(bChain, crnt, false); // setting the transaction t to the returned transaction from chainSearch
        calFromOrTo(crnt, t); // calculating the values based on what previous ID was found
    }if(chainSearch(bChain, crnt, false).getID() == 100) { // calling chainSearch with the bool parameter being false (false associates with toIDs), and assuming that if getID() == 100, then a previous transaction was not found
        crnt.setToValue(100); // leaving the current transaction's toValue as 100
    }
    if(chainSearch(bChain, crnt, true).getID() == 100) { // calling chainSearch with the bool parameter being true (true associates with fromIDs), and assuming that if getID() == 100, then a previous transaction was not found
        crnt.setFromValue(100); // leaving the current transaction's fromValue as 100
    }
}
void blockChain::insertTransaction(transaction t) { // inserting a transaction for a blockChain object
    if(bChain.empty() || bChain.back().getTransactions().size() == bChain.back().getMaxNumTransactions()) { // if there are no blocks in bChain, or if the the block being inserted to is full
        currentNumBlocks++; // increment currentNumBlocks
        block b = block(currentNumBlocks, transactionsPerBlock); // create a new block to insert transactions into
        calc(t); // perform the calculations for the transaction t to be inserted
        b.insertTransactions(t); // inserting the transaction t
        cout << "Inserting transaction to block #" << b.getBlockNumber(); // print statement to show what block the transactions are being inserted into
        bChain.push_back(b); // inserting the block into bChain
    }
    else {
        calc(t); // perform the calculations for the transaction t to be inserted
        bChain.back().insertTransactions(t); // insert the transaction t into the block
        cout << "Inserting transaction to block #" << bChain.back().getBlockNumber(); // print statement to show what block the transactions are being inserted into
    }
}
list<block> blockChain::getChain() { // getter that returns the bChain List
    return bChain; // returning bChain
}
void blockChain::displayChain() { // display method for blockChain that calls the block class display method
    cout << "Current number of blocks: " << currentNumBlocks << endl; // print statement to show the current number of blocks in a blockChain object
        for(block b:bChain)  { // for each loop to iterate through each block in a chain
            b.displayBlock(); // display each block in a chain
        }
}
transaction blockChain::chainSearch(list<block> chain, transaction t, bool fromOrTo) { // search method that iterates across each block within a blockChain, which then iterates through each transaction of each block in a blockChain. this method returns the nearest transaction where a fromID or a toID is found
    list<block> :: reverse_iterator reverse; // reverse iterator object to start from the end of the blockChain
    if(!fromOrTo) { // bool being false means we are dealing with a toID
        for (reverse = chain.rbegin(); reverse != chain.rend(); reverse++) { // iterating through each block in the chain
            for (int i = reverse->getTransactions().size() - 1; i >= 0; i--) { // iterating through each transaction in a block
                if (reverse->getTransactions()[i].getToID() == t.getToID()) { // if the toID of the transaction in the block at index i is equal to the current transaction's toID
                    return reverse->getTransactions()[i]; // return this transaction
                }
                if(reverse->getTransactions()[i].getFromID() == t.getToID()) { // if the fromID of the transaction in the block at index i is equal to the current transaction's toID
                    return reverse->getTransactions()[i]; // return this transaction
                }
        }
    }
    }
    if(fromOrTo) { // bool being true means we are dealing with a fromID
        for (reverse = chain.rbegin(); reverse != chain.rend(); reverse++) { // iterating through each block in the chain
            for (int i = reverse->getTransactions().size() - 1; i >= 0; i--) { // iterating through each transaction in a block
                if (reverse->getTransactions()[i].getFromID() == t.getFromID()) { // if the fromID of the transaction in the block at index i is equal to the current transaction's fromID
                    return reverse->getTransactions()[i]; // return this transaction
                }
                if (reverse->getTransactions()[i].getToID() == t.getFromID()) { // if the toID of the transaction in the block at index i is equal to the current transaction's fromID
                    return reverse->getTransactions()[i]; // return this transaction
                }
            }
        }
    }
    return transaction(); // returning a default transaction if no previous transaction was found
    }
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class blockNetwork
{
    int numNodes;                // maintain the number of nodes in the network
    vector<blockChain> allNodes; // vector of all the blockChains in the network
    vector<int> u;               // edge list u node
    vector<int> v;               // edge list v node

public:
    blockNetwork();                  // default constructor
    blockNetwork(int numberOfNodes); // non default constructor
    void insertChain(transaction, int); // insert method to insert new transaction into the block chain in a specific node
    void networkDisplay(); // display method for a blockNetwork that calls the display method from the blockChain class
    void fillEdgeLists(int, int); // method to fill the u and v edge lists
    vector<int> displayUList(); // method to display the u edge list
    vector<int> displayVList(); // method to display the v edge list
    vector<blockChain>& getBlockChains(); // method that returns allNodes
};
blockNetwork::blockNetwork(int numberOfNodes) { // non default constructor
    numNodes = numberOfNodes; // assigning numNodes with the number of nodes
}
void blockNetwork::insertChain(transaction t, int node) { // insert method to insert new transaction into the block chain in a specific node
    allNodes[node].insertTransaction(t); // inserting the transaction t into a specific blockChain by calling the blockChain insertTransaction method
}
void blockNetwork::networkDisplay(){ // display method for a blockNetwork that calls the display method from the blockChain class
    for(int i = 0; i < numNodes; i++) { // displaying each blockChain
        cout << "~~~ Node " << i << ":" << endl; // print statement to show which node is being displayed
        allNodes[i].displayChain(); // calling the blockChain display method for each blockChain in allNodes
        }
    }
void blockNetwork::fillEdgeLists(int left, int right) { // method to fill the u and v edge lists
    u.push_back(left); // inserting the left edge into u
    v.push_back(right); // inserting the right edge into v
}
vector<int> blockNetwork::displayUList() { // method to display the u edge list
    for(int i = 0; i < u.size(); i++) { // looping through each element of u
        cout << u[i] << endl; // printing each element of u
    }
}
vector<int> blockNetwork::displayVList() { // method to display the v edge list
    for(int i = 0; i < u.size(); i++) { // looping through each element of v
        cout << v[i] << endl; // printing each element of v
    }
}
vector<blockChain>& blockNetwork::getBlockChains() { // method that returns allNodes
    return allNodes; // returning allNodes
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main() {
    int node; // int to store the node from input file
    int transactionID; // int to store each transaction ID from input file
    int fromID; // int to store each fromID from input file
    int toID; // int to store each toID from input file
    int transferAmount; // int to store each transfer amount from input file
    string timeStamp; // string to store the timeStamp for each transaction from input file

    int numNodesInNetwork; // number of nodes in the network

    cin >> numNodesInNetwork; // reading in from input
    cout << "Number of nodes: " << numNodesInNetwork << endl; // printing the number of nodes

    int numTransactionsPerBlock; // max transactions per block

    cin >> numTransactionsPerBlock; // reading in from input
    cout << "Number of transactions per block: " << numTransactionsPerBlock << endl; // printing the number of transactions per block

    int totalNumTransactions; // total transactions to be read from the input file

    cin >> totalNumTransactions; // reading in from input
    cout << "Total number of transactions: " << totalNumTransactions << endl; // printing the total number of transactions

    int numEdges; // int to store the number of edges
    cin >> numEdges; // reading number of edges from input file

    int uEdge; // int to store the left edge (u)
    int vEdge; // int to store the right edge (v)

    blockNetwork *n1 = new blockNetwork(numNodesInNetwork); // creating a new blockNetwork object
    n1->getBlockChains().push_back(blockChain(numTransactionsPerBlock)); // inserting a blockChain into the network
    int node2 = 0; // int to determine when the value of node changes

    for (int i = 0; i < numEdges; i++) { // loop to fill the u and v edge lists
        cin >> uEdge, cin >> vEdge; // reading in the edges from the input file
        n1->fillEdgeLists(uEdge, vEdge); // calling fillEdgeLists method to fill the u and v lists
    }
    for(int i = 0; i < totalNumTransactions; i++) { // looping to insert transactions
        cin >> node, cin >> transactionID, cin >> fromID, cin >> toID, cin >> transferAmount, cin >> timeStamp; // reading transaction information from input file
        transaction t = transaction(transactionID, fromID, toID, transferAmount, timeStamp); // new transaction based on input file
        if(node != node2) { // if the node value changes
            n1->getBlockChains().push_back(blockChain(numTransactionsPerBlock)); // create a new blockChain and insert into n1
            node2 = node; // update the value of node2
        }
        n1->insertChain(t, node); // inserting transactions at a specific node
        cout << " in node " << node << endl; // printing what node we are inserting into
    }

     n1->networkDisplay(); // calling the blockNetwork display method on n1

    delete n1; // deleting the blockNetwork pointer object n1
    return 0;
}