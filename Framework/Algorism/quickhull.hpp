#pragma once
#include <cassert>
#include <limits>
#include <memory>
#include <set>
#include <utility>
#include "geommath.hpp"

namespace My {
    class QuickHull {
    public:
        QuickHull() = default;
        ~QuickHull() = default;
        QuickHull(const PointSet& point_set) : m_PointSet(point_set) {}
        QuickHull(PointSet&& point_set) : m_PointSet(std::move(point_set)) {}
        void AddPoint(const PointPtr& new_point) { m_PointSet.insert(new_point); }
        void AddPoint(PointPtr&& new_point) { m_PointSet.insert(std::move(new_point)); }
        void AddPointSet(const PointSet& point_set) { m_PointSet.insert(point_set.begin(), point_set.end()); }
        const PointSet& GetPointSet() const { return m_PointSet; }
        void ComputeHull() { ComputeHullInternal(); }
        const Polyhedron& GetHull() const { return m_ConvexHull; }

    protected:
        void ComputeHullInternal();

    protected:
        PointSet m_PointSet;
        Polyhedron m_ConvexHull;
    };
}