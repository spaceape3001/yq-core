#include "preamble.hpp"
#include "GraphTraitAnalyzer.hpp"
#include <cstdint>


#ifndef NDEBUG
        /*
            Following are for testing the syntax of the traits, etc.
        */
    namespace {
        using namespace yq;
        
        struct TestGraph1 {

            struct Graph;
            struct Node;
            struct Edge;
            struct Port;
            
            Edge*   edge(uint64_t) const;
            Graph*  graph(uint64_t) const;
            Node*   node(uint64_t) const;
            Port*   port(uint64_t) const;
        };
        
        static_assert( has_edge<TestGraph1> );
        static_assert( has_graph<TestGraph1> );
        static_assert( has_node<TestGraph1> );
        static_assert( has_port<TestGraph1> );

        [[maybe_unused]] GraphTraitAnalyzer<TestGraph1>      tg1;

        struct TestGraph1a {

            struct Node;
            struct Edge;
            
            Edge*   edge(uint64_t) const;
            Node*   node(uint64_t) const;
        };

        static_assert( has_edge<TestGraph1a> );
        static_assert( !has_graph<TestGraph1a> );
        static_assert( has_node<TestGraph1a> );
        static_assert( !has_port<TestGraph1a> );

        [[maybe_unused]] GraphTraitAnalyzer<TestGraph1a>    tg1a;

        struct TestGraph2 {

            struct Graph;
            struct Node;
            struct Edge;
            struct Port;
            
            static Edge*   edge(uint64_t);
            static Graph*  graph(uint64_t);
            static Node*   node(uint64_t);
            static Port*   port(uint64_t);
        };

        static_assert( has_edge<TestGraph2> );
        static_assert( has_graph<TestGraph2> );
        static_assert( has_node<TestGraph2> );
        static_assert( has_port<TestGraph2> );

        [[maybe_unused]] GraphTraitAnalyzer<TestGraph2>     tg2;
        
        struct TestGraph2a {

            struct Node;
            struct Edge;
            
            static Edge*   edge(uint64_t);
            static Node*   node(uint64_t);
        };
     
        static_assert( has_edge<TestGraph2a> );
        static_assert( !has_graph<TestGraph2a> );
        static_assert( has_node<TestGraph2a> );
        static_assert( !has_port<TestGraph2a> );

        [[maybe_unused]] GraphTraitAnalyzer<TestGraph2a>    tg2a;
    }
    
#endif

