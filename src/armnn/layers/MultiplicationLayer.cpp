//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//
#include "MultiplicationLayer.hpp"

#include "LayerCloneBase.hpp"

#include <armnn/TypesUtils.hpp>
#include <backendsCommon/WorkloadData.hpp>
#include <backendsCommon/WorkloadFactory.hpp>

namespace armnn
{

MultiplicationLayer::MultiplicationLayer(const char* name)
    : ArithmeticBaseLayer(2, 1, LayerType::Multiplication, name)
{
}

std::unique_ptr<IWorkload> MultiplicationLayer::CreateWorkload(const Graph& graph,
                                                               const IWorkloadFactory& factory) const
{
    MultiplicationQueueDescriptor descriptor;
    return factory.CreateMultiplication(descriptor, PrepInfoAndDesc(descriptor, graph));
}

MultiplicationLayer* MultiplicationLayer::Clone(Graph& graph) const
{
    return CloneBase<MultiplicationLayer>(graph, GetName());
}

} // namespace armnn
