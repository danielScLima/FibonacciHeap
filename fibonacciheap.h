#ifndef FIBONACCI_HEAP_H
#define FIBONACCI_HEAP_H

#include <iostream>
#include <vector>

//Indicando que já teve um filho removido
/*!
 * \brief The Marked enum
 */
enum Marked
{
    YES, NO
};

/*!
 * \brief The FibonacciHeapNode struct
 */
struct FibonacciHeapNode
{
    /*!
     * \brief FibonacciHeapNode
     * \param data
     */
    FibonacciHeapNode(int data)
    {
        this->data = data;
        next = nullptr;
        previous = nullptr;
    }

    int data = 0;
    int grau = 0; //quantidade de filhos
    Marked marked = NO;
    struct FibonacciHeapNode* next = nullptr;
    struct FibonacciHeapNode* previous = nullptr;

    struct FibonacciHeapNode* father = nullptr;
    struct FibonacciHeapNode* children = nullptr; //aponta para apenas um filho
};

/*!
 * \brief The FibonacciHeap class
 */
class FibonacciHeap
{
public:
    /*!
     * \brief FibonacciHeap
     */
    FibonacciHeap();

    ~FibonacciHeap();
    /*!
     * \brief insertBeforeStart
     * \param data
     */
    void insertBeforeStart(int data);

    /*!
     * \brief getElementsAsVector
     * \return
     */
    std::vector<std::string> getElementsAsVector();

    /*!
     * \brief getDrawModeOne
     * \return
     */
    const std::string getDrawModeOne();
    /*!
     * \brief getDrawModeTwo
     * \return
     */
    const std::string getDrawModeTwo();

    /*!
     * \brief insertBeforeStart
     * \param tmp
     */
    void insertBeforeStart(FibonacciHeapNode *tmp);

    /*!
     * \brief search
     * \param data
     * \return
     */
    FibonacciHeapNode* search(int data);
    /*!
     * \brief searchStartingOfNode
     * \param data
     * \param initial
     * \return
     */
    FibonacciHeapNode *searchStartingOfNode(int data, FibonacciHeapNode *initial);
    /*!
     * \brief decrementKey
     * \param dataKey
     * \param decrement
     * \return
     */
    bool decrementKey(int dataKey, int decrement);

    /*!
     * \brief getDrawStartingOfNodeByModeTwo
     * \param initial
     * \param NodeDeclaration
     * \param linksDeclaration
     */
    void getDrawStartingOfNodeByModeTwo
    (
        FibonacciHeapNode *initial,
        std::string &NodeDeclaration,
        std::string &linksDeclaration
    );
    /*!
     * \brief getCodeOfNode
     * \param node
     * \param NodeDeclaration
     */
    void getCodeOfNode(FibonacciHeapNode *node, std::string& NodeDeclaration);

    /*!
     * \brief deleteMinInterface
     * \return
     */
    FibonacciHeapNode *deleteMinInterface();

    /*!
     * \brief getStartNode
     * \return
     */
    FibonacciHeapNode *getStartNode();

    /*!
     * \brief getMinNode
     * \return
     */
    FibonacciHeapNode *getMinNode();
private:
    int countOfRoots = 0;
    int countOfNodes = 0;
    struct FibonacciHeapNode* start = nullptr;
    FibonacciHeapNode *nodeWithMinimumValue = nullptr;

    /*!
     * \brief getDrawStartingOfNodeByModeOne
     * \param node
     * \param textToFile
     */
    void getDrawStartingOfNodeByModeOne
    (
        FibonacciHeapNode *node,
        std::string& textToFile
    );

    /*!
     * \brief mergeSubTrees
     * \param rootOne
     * \param rootTwo
     * \return
     */
    FibonacciHeapNode *mergeSubTrees
    (
        FibonacciHeapNode *rootOne,
        FibonacciHeapNode *rootTwo
    );

    /*!
     * \brief removeBeforeStart
     * \return
     */
    FibonacciHeapNode *removeBeforeStart();
    /*!
     * \brief consolidateFunction
     */
    void consolidateFunction();
    /*!
     * \brief increaseMarkAndCheckCondition
     * \param node
     */
    void increaseMarkAndCheckCondition(FibonacciHeapNode *node);
    /*!
     * \brief changeNodePosition
     * \param node
     */
    void changeNodePosition(FibonacciHeapNode *node);
    /*!
     * \brief deleteMin
     * \return
     */
    FibonacciHeapNode *deleteMin();

    /*!
     * \brief dealockList
     * \param initial
     * \param currentNode
     */
    void dealockList(FibonacciHeapNode *initial, FibonacciHeapNode *currentNode);
};

#endif // FIBONACCI_HEAP_H
