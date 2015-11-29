/*
 * Copyright (C) 2015 Fondazione Istituto Italiano di Tecnologia
 * Authors: Silvio Traversaro
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 *
 */

#ifndef IDYNTREE_LINK_STATE_H
#define IDYNTREE_LINK_STATE_H

#include <iDynTree/Core/Transform.h>
#include <iDynTree/Core/Twist.h>
#include <iDynTree/Core/SpatialAcc.h>
#include <iDynTree/Core/Wrench.h>

#include <iDynTree/Model/Indeces.h>

#include <vector>

namespace iDynTree
{
    class Model;

    class LinkPositions
    {
    private:
        std::vector<iDynTree::Transform> m_linkPos;

    public:
        LinkPositions(unsigned int nrOfLinks = 0);
        LinkPositions(const iDynTree::Model & model);

        void resize(unsigned int nrOfLinks);
        void resize(const iDynTree::Model & model);

        iDynTree::Transform & operator()(const LinkIndex link);
        const iDynTree::Transform & operator()(const LinkIndex link) const;

        ~LinkPositions();
    };

    /**
     * Vector of wrenches connected in some way to the link of a model.
     *
     * It is used to model both the total external wrench
     * acting on a  link (LinkExternalWrenches), or the internal wrenches
     * that a link excerts on his parent (given a Traversal)
     * computed as a by product by the dynamic loop of the RNEA ( RNEADynamicPhase ).
     */
    class LinkWrenches
    {
    private:
        std::vector<iDynTree::Wrench> m_linkWrenches;

    public:
        /**
         * Create a LinkWrenches vector, with the size given
         * by nrOfLinks .
         *
         * @param[in] nrOfLinks the size of the vector.
         */
        LinkWrenches(unsigned int nrOfLinks = 0);
        LinkWrenches(const iDynTree::Model & model);

        /**
         * Resize the vector to have size nrOfLinks.
         *
         * @param[in]
         */
        void resize(unsigned int nrOfLinks);
        void resize(const iDynTree::Model & model);



        iDynTree::Wrench & operator()(const LinkIndex link);
        const iDynTree::Wrench & operator()(const LinkIndex link) const;

        ~LinkWrenches();
    };

    /**
     * Vector of the total external wrench acting on each link.
     *
     * The wrench returned by operator(i) is the sum of all external wrenches
     * (thus excluding the wrench applied on the link by other links in the model)
     * that the environment applies on the link $i$, expressed (
     * both orientation and point) with respect to the reference frame of link i.
     */
    typedef LinkWrenches LinkExternalWrenches;

    /**
     * Vector of the wrenches acting that a link excert on his parent,
     * given a Traversal.
     *
     * Given a Traversal with base link b, the wrench returned by operator(i) is the wrench
     * the parent of link i excerts on link i, expressed (both orientation
     * and point) with respect to the reference frame of link i.
     */
    typedef LinkWrenches LinkInternalWrenches;

    /**
     * Class for storing a vector of SpatialInertia objects , one for each link in a model.
     */
    class LinkInertias
    {
    private:
        std::vector<iDynTree::SpatialInertia> m_linkInertials;

    public:
        LinkInertias(unsigned int nrOfLinks = 0);
        LinkInertias(const iDynTree::Model & model);

        void resize(unsigned int nrOfLinks);
        void resize(const iDynTree::Model & model);

        iDynTree::SpatialInertia & operator()(const LinkIndex link);
        const iDynTree::SpatialInertia & operator()(const LinkIndex link) const;

        ~LinkInertias();
    };

    typedef LinkInertias LinkCompositeRigidBodyInertias;

    /**
     * Class for storing a vector of ArticulatedBodyInertias objects , one for each link in a model.
     */
    class LinkArticulatedBodyInertias
    {
    private:
        std::vector<iDynTree::ArticulatedBodyInertia> m_linkABIs;

    public:
        LinkArticulatedBodyInertias(unsigned int nrOfLinks = 0);
        LinkArticulatedBodyInertias(const iDynTree::Model & model);

        void resize(unsigned int nrOfLinks);
        void resize(const iDynTree::Model & model);

        iDynTree::ArticulatedBodyInertia & operator()(const LinkIndex link);
        const iDynTree::ArticulatedBodyInertia & operator()(const LinkIndex link) const;

        ~LinkArticulatedBodyInertias();
    };

    /**
     * Class for storing a vector of twists, one for each link in a model.
     */
    class LinkVelArray
    {
    private:
        std::vector<iDynTree::Twist> m_linkTwist;

    public:
        LinkVelArray(unsigned int nrOfLinks = 0);
        LinkVelArray(const iDynTree::Model & model);

        void resize(unsigned int nrOfLinks);
        void resize(const iDynTree::Model & model);

        iDynTree::Twist & operator()(const LinkIndex link);
        const iDynTree::Twist & operator()(const LinkIndex link) const;

        ~LinkVelArray();
    };

    /**
     * Class for storing a vector of spatial accelerations,
     *  one for each link in a model.
     */
    class LinkAccArray
    {
    private:
        std::vector<iDynTree::SpatialAcc> m_linkAcc;

    public:
        LinkAccArray(unsigned int nrOfLinks = 0);
        LinkAccArray(const iDynTree::Model & model);

        void resize(unsigned int nrOfLinks);
        void resize(const iDynTree::Model & model);

        iDynTree::SpatialAcc & operator()(const LinkIndex link);
        const iDynTree::SpatialAcc & operator()(const LinkIndex link) const;

        unsigned int getNrOfLinks() const;

        ~LinkAccArray();
    };
}

#endif /* IDYNTREE_LINK_STATE_H */