/* License: MIT. See LICENSE in root directory. */

/**
 * \date 2020/06/29
 */

#pragma once

namespace Ensemble
{

/**
 *
 */
template<typename ItemType>
struct DlListNode
{
    ItemType* mpNext, * mpPrev;
};

/**
 *
 */
template<typename ItemType>
struct DlListNodeFinder
{
    DlListNode<ItemType>* mListNode;
};

/**
 *
 */
template<typename ItemType, typename FinderType = DlListNodeFinder<ItemType>/*, typename T3 = WeakReferenceLifetimePolicy<T1>*/>
class DlList
{
protected:

    ItemType* mpHead, * mpTail;

public:

    ~DlList();

public:

    void Remove(ItemType*);

    void RemoveAll();
};

} // namespace Ensemble
